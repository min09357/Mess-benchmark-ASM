


지금은 traffic generator로 stream과 randomaccess를 사용중


근데 이번엔 각 코어가 한 dram bank에만(채널, 랭크 등 모든 계층구조가 같음. 전부 0번인 곳으로 설정) 매 접근이 row miss를 일으키도록 하고 싶어.
즉 코어 0는 자기 영역에서 bank 0의 row n, col 0 -> row n+1, col0 -> ... -> row m, col0 -> row n, col 1 -> ...
이런식으로 접근하는거지.
코어1도 마찬가지로 같은 bank 에 접근하고.
이 때 col은 cache line 단위야. 즉 64B.

메모리 컨트롤러에서 physical address를 실제 dram의 mapping으로 변환하는 함수는 알고 있다는 가정이야. 
좀 더 자세히 설명하면 예를들어 DDR5일 때 채널 2개, 채널 당 DIMM(slot이라고 표현) 2개, DIMM 당 sub channel 2개, 채널 당 랭크 2개, 랭크 당 뱅크그룹 8개, 뱅크그룹 당 뱅크 4개인 시스템에는 채널을 결정하는 비트가 1개, DIMM을 결정하는 비트 1개, 서브채널비트 1개, 랭크비트 1개, 뱅크그룹 비트 3개, 뱅크 비트 2개가 나와야 할것이고, 이 비트들은 특정 함수로 정해지겠지. 함수 개수는 비트개수와 같고.
이 함수는 physical address에서 특정 비트들을 뽑아내서(mask로) 해당 비트들을 xor해서 정해지는거야.
만약 랭크가 1개라거나, DDR4라서 서브채널이 없어 구분할 필요가 없거나 하면 해당 함수의 mask는 0x0이 들어갈거고.
또한 row와 column을 결정하는 bit mask도 주어질거고.
이런 mask는 코드에 적을거야.
아래 코드가 내가 다른 프로젝트에서 사용한 방식인데 참고하고.


int applyXorFunctions(uint64_t physAddr, const vector<uint64_t>& masks) {
    int result = 0;
    for (size_t i = 0; i < masks.size(); ++i) {
        if (__builtin_parityl(physAddr & masks[i])) {
            result |= (1 << i);
        }
    }
    return result;
}

BankInfo getBankFromPhysicalAddr(uint64_t physAddr) {
    BankInfo info;
    info.ch   = applyXorFunctions(physAddr, g_config.ch_masks);
    info.slot = applyXorFunctions(physAddr, g_config.slot_masks);
    info.sc   = applyXorFunctions(physAddr, g_config.sub_ch_masks);
    info.rk   = applyXorFunctions(physAddr, g_config.rank_masks);
    info.bg   = applyXorFunctions(physAddr, g_config.bg_masks);
    info.bank = applyXorFunctions(physAddr, g_config.bank_masks);
    info.row  = (int)_pext_u64(physAddr, g_config.row_mask);
    info.col  = (int)_pext_u64(physAddr, g_config.col_mask);
    return info;
}


page의 경우 1GB huge page를 사용하도록. 반드시.

mmap 하고 나서 시작 주소부터 64바이트씩(한 col 단위로) 뛰어가며 physical address를 구해 몇번 뱅크인지 알아내서 목표 뱅크면 해당 address(virtual)를 따로 array에 저장. 이후 접근 sequence에 맞게 sorting 하거나 처음부터 위치에 맞게 저장.

traffic을 generate할 때 이 저장된 주소로 접근할거야. 참고로 접근할 때 단위를 8B로 해도 어차피 캐시 블록 단위 64B로 접근하니까 해당 주소를 uint64_t로 간주해서 접근하는게 좋을듯.


그리고 각 코어에서 1GB 페이지 한개가 뱅크 하나만 보면 너무 많을까 걱정하지 않아도 되는게 실험은 거의 채널 1개로 할거라 전체 working set은 LLC보다 훨씬 클거야. 나중에 늘릴 수 만 있게 해.


캐시의 경우 traffic generate하기 전 각 코어에서 자기의 할당한 huge page 항목에 대해 딱 한번만 전부 flush하도록.

