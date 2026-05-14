현재 memory traffic을 생성하는 로직은 sequential하게 접근하는 stream_mpi를 사용해.
그런데 이번에는 random access로 하도록 만들고 싶어.
config에서 RANDOM_GENERATOR가 stream이면 기존의 stream을, random이면 랜덤을 사용하도록.

우선 랜덥 접근할 방식은 core_single_cpu.c의 RandomAccessUpdate()에서 주석처리돼있는 scalar equivalent 방식으로 하고싶어.

scalar equivalent:
for (i=0; i<NUPDATE; i++) {
   ran = (ran << 1) ^ (((s64Int) ran < 0) ? POLY : 0);
   table[ran & (TableSize-1)] ^= ran;
}

일단 어셈블리로 만들진 않고 c코드로 할거야.

read를 할 때면 함수 내부 local variable에 add를 해주고
local_variable += table[ran & (TableSize-1)]

write할 때면 그 위치에 0을 쓸거야(ran과 XOR이 아님).
table[ran & (TableSize-1)] = 0

stream에서 처럼 read, write 비율에 따라 이 read와 write의 비율을 맞출거야.

위의 코드처럼 for문 블록에 한 번의 접근만 있는게 아니라 stream의 assembly처럼 총 100 개의 접근이 있어야돼.

그리고 5회의 접근마다 중간에 nop을 넣어줄거야. 얼마나 넣을지는 stream의 경우와 같게.

POLY는 7로 define.

table은 stream에서 array를 할당할 때와 같이 일단 1GB page로 시도, 하나라도 실패하면 2MB로 시도, 또 실패하면 4KB로 만들거야.

table size는 각 스레드당 256MB로 할거야. 근데 주석으로 1G 전부를 사용하는 경우도 해줘.