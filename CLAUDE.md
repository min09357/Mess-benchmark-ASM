# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## 개요

Mess 벤치마크는 메모리 시스템 성능을 나타내는 **대역폭–지연 시간 곡선**을 생성한다. read/write 비율과 NOP pause 값(메모리 압력 조절)의 조합마다 다음을 수행한다:

1. core 0을 제외한 모든 코어에서 트래픽 제너레이터(stream 또는 random) 실행
2. 시스템 안정화 대기 (`TIME_STREAM_STABILIZE`초)
3. core 0에서 포인터 체이싱으로 지연 시간 측정
4. `perf` uncore 카운터(CAS 명령)로 대역폭 측정
5. 트래픽 제너레이터 종료
6. 원시 데이터를 후처리해 Savitzky–Golay 스무딩된 곡선 생성

현재 작업 플랫폼: `CPU/Actual-hardware/x86/Intel-SapphireRapids-Xeon-Gold-6438Y+/`. 아래 명령은 모두 해당 디렉토리 기준.

## 사전 요구사항

- `gcc`, `mpicc` (MPICH — Makefile에 `export MPICH_CC=/usr/bin/gcc` 설정해 conda 충돌 방지)
- Python 3: `matplotlib`, `toml`, `pandas`, `numpy`, `scipy`, `pyarrow`, `seaborn`
- `perf` uncore 카운터 접근 권한: `/proc/sys/kernel/perf_event_paranoid`가 `-1`이어야 함

```bash
echo -1 | sudo tee /proc/sys/kernel/perf_event_paranoid
```

## 실행 명령

```bash
cd CPU/Actual-hardware/x86/Intel-SapphireRapids-Xeon-Gold-6438Y+

# 전체 실행: 컴파일 → 측정 → 후처리
./runner.sh

# 후처리만 재실행 (기존 measuring/ 결과 재파싱, 메인 루프 주석 처리됨)
./postprocess.sh

# 그래프만 재생성 (모듈 로드 라인이 활성화돼 있어 Ubuntu에서는 그대로 실행 시 실패 — 주석 처리 필요)
./generateFigure.sh

# 측정 결과 및 컴파일된 바이너리 삭제 (단, measuring/log/는 보존)
./clear.sh
```

## 설정

`config/sapphireRapids_ddr5.toml`을 수정한다. `runner.sh`가 `create_runner_config.sh`를 호출해 TOML을 `config.sh`(key=value 형식의 셸 변수 파일)로 변환하고, 이후 모든 스크립트가 이를 `source`해서 사용한다. `create_runner_config.sh`의 `param_map`에 없는 키는 변환되지 않으므로 새 파라미터 추가 시 매핑도 갱신 필요.

주요 파라미터:
- `stream-core-list` / `stream-core-count` / `stream-core-count-socket`: 트래픽 제너레이터가 사용할 코어 — 각 소켓의 core 0(SMT 쌍 포함) 제외 필수. socket 수는 `stream-core-count / stream-core-count-socket`로 자동 계산됨
- `random-generator`: `"stream"` (순차 접근) 또는 `"random"` (HPCC LFSR 랜덤 접근)
- `stream-pauses`: 메모리 명령 사이 NOP 수 리스트 — 곡선의 데이터 포인트가 됨 (0=최대 압력, 큰 값=언로드)
- `rwratio-min/max/step`: 읽기 비율 스윕 (100 = 읽기 전용)
- `point-reps`: 포인트당 반복 횟수 — 이상값 제거(평균 ±1σ 바깥) 후 평균에 사용되므로 최소 3 권장
- `ptrchase-array-size`: LLC 크기의 4배 이상이어야 캐시 히트율 ~0% 달성
- `stlb-hit-latency`: SPR에서는 ns 단위 (다른 아키텍처는 cycles)

## 아키텍처

### 측정 루프 (`runner.sh` → `submit_main.job`)

`runner.sh`가 `point_reps × rwratio × pause` 삼중 루프를 돌며 각 포인트마다 `bash submit_main.job`을 호출한다. `submit_main.job`의 순서:

1. **`launch_stream`**: `numactl -C ${STREAM_CORE_LIST}` + `mpirun -n ${STREAM_CORE_COUNT}`로 트래픽 제너레이터를 백그라운드 실행하고 PID 저장
2. **`sleep ${TIME_STREAM_STABILIZE}`**: 시스템 정상 상태 도달 대기
3. **`measure_latency`**: core 0에서 `./ptr_chase` 실행 (perf 카운터 출력은 ptr_chase 내부 `perf_helper.h`가 직접 emit)
4. **`measure_bandwidth`**: `numactl -C 0 perf stat -a --per-socket -e unc_m_cas_count.rd,unc_m_cas_count.wr,unc_m_cas_count.all sleep ${BW_TOOL_SAMPLE_TIME}` — 별도의 워크로드 없이 uncore 카운터만 샘플링
5. **`terminate_stream`**: 저장된 PID의 cmdline에서 `-r ${rd_percentage} -p ${pause}`가 일치하는지 확인 후 `SIGKILL`

원시 결과 저장 경로 (`OUTPUT` TOML 키가 비어있어 `measuring/` 직속에 저장됨):
- `measuring/bw/bw_perf_<rwratio>_<pause>.txt`
- `measuring/lat/lat_perf_<rwratio>_<pause>.txt`
- `measuring/log/stream_<rwratio>_<pause>.log`

### 트래픽 제너레이터 (`src/`)

- **`stream_mpi/`**: 순차 load/store 스트림. `-r` 읽기 비율, `-p` NOP pause 수
- **`RandomAccess_hpcc/`**: HPCC LFSR 기반 랜덤 접근. Makefile에서 `random_update.c`만 `-fno-tree-vectorize -fno-tree-slp-vectorize`로 컴파일 — 100개의 명시적 load/store가 AVX-512 패킹 연산으로 묶이지 않고 개별 명령으로 유지되도록 함
- **`ptr_chase/`**: 포인터 체이싱 지연 시간 벤치마크
  - Makefile이 `awk`로 `loop_template.h`를 `PTRCHASE_NUM_INSTRUCTIONS / PTRCHASE_NUM_ITERATIONS`번 복제해 `loop.h` 생성 → 컴파일 타임 루프 언롤링
  - `arraygen`이 미리 LFSR로 무작위 순열 배열(`array.dat`)을 생성
  - `-O0`으로 컴파일 (포인터 체이싱 의존성 보존)

### 후처리 파이프라인 (`processing/`)

`main.py`가 전체를 조율한다:

1. **`parse.py` → `line_parser.py`**: 원시 perf 출력 파일을 읽고 도구/지표별 파서 클래스에 위임
   - `BandwidthPerfLineParser`: `unc_m_cas_count.{rd,wr}` 행과 `seconds` 행 추출
   - `LatencyPerfLineParser`: `:u` 접미사가 붙은 카운터 행과 `seconds time` 행 추출
2. **`utils.split_dataframe_by_rd_pause_percentage` → `discard_outliers`**: 각 (rw, pause) 그룹 내에서 평균 ±1σ 바깥 측정 제거 (bandwidth만 — latency 이상값 제거는 main.py에서 주석 처리됨)
3. **`calculator.py`**:
   - `BandwidthCalculator`: `bandwidth = Σ(CAS_rd + CAS_wr) × 64B / runtime`. socket0 컬럼만 사용. `rd_mapped = CAS_rd / (CAS_rd + CAS_wr)`도 계산
   - `LatencyCalculator`: `latency_ns = (seconds_user × 1e9 − r1012 / CPU_FREQ − STLB_HIT_LATENCY × r2012) / PTRCHASE_NUM_INSTRUCTIONS` — `r1012`(페이지워크 사이클)와 `r2012`(STLB 히트 횟수)로 TLB 오버헤드 제거
   - `MeanCalculator`: `(type, rd_percentage, pause)`로 그룹화해 mean/std/min/max 집계
4. **`corrections.smooth_curves`**: Savitzky–Golay 필터(window/polyorder는 `[Processing]` 섹션에서 설정)로 (bandwidth, latency) 점들을 곡선 스무딩
5. 최종 출력: `measuring/output/bandwidth-latency.csv`, `bandwidth-latency.pdf`

## 로컬 적응 사항 (upstream 대비 변경점)

`CPU/Actual-hardware/x86/Intel-SapphireRapids-Xeon-Gold-6438Y+/process.md`에 상세 기록. Slurm/Intel 컴파일러 없는 Ubuntu 환경 실행을 위한 변경:

- **`submit_main.job`**: SBATCH 헤더 및 `module` 명령 주석 처리, `srun` → `mpirun` 교체, 중단 시 mpirun 정리를 위한 `trap … EXIT` 추가, `perf`가 천 단위 구분자 쉼표를 출력하는 문제 방지용 `export LC_ALL=C` 추가
- **`runner.sh`**: 메인 루프에서 `sbatch` → `bash ./submit_main.job`, squeue 대기 루프 제거, postprocess 단계 활성화
- **`src/ptr_chase/Makefile`**: `SHELL := /bin/bash` 추가 (Ubuntu의 `/bin/sh`인 dash에서 `bc <<<` here-string 실패)
- **`src/stream_mpi/Makefile`**: `MPICC=mpicc` (`icx` 대체), `MPI_LIB`/`MPI_INCLUDE` 비움, `export MPICH_CC=/usr/bin/gcc`
- **`src/RandomAccess_hpcc/Makefile`**: 동일 + `RANDUPD_CFLAGS`로 벡터화 무력화
- **`src/ptr_chase/ptr_chase.c`**, **`src/ptr_chase/arraygen.c`**: `array` 변수를 `mess_array`로 전체 이름 변경 (`using namespace std`로 인한 `std::array` 이름 충돌 해결)
- **`processing/calculator.py`**: SPR perf 이벤트 코드 수정 — `r1012`(event 0x12, umask 0x10) = 페이지워크 사이클, `r2012`(event 0x12, umask 0x20) = STLB 히트 횟수 (upstream에서 `r1008`/`r2008`로 잘못 적힌 부분 수정)

## 주의 사항

- TOML의 `lat-tool-counters`에는 여전히 `r2008:u,r1008:u`가 남아있지만, 실제로는 `submit_main.job`이 `./ptr_chase` 바이너리를 직접 실행하며 perf 이벤트는 `ptr_chase.c` 내부의 `perf_helper.h`가 emit한다. 따라서 이 TOML 값은 현재 사용되지 않는다.
- `postprocess.sh`와 `generateFigure.sh`는 `runner.sh`의 복사본이며 `mkdir` 단계에서 오타 변수 `ATE`(`DATE` 아님)를 export하나, 이후 사용되지 않아 동작에는 영향 없음.
- `generateFigure.sh`는 최상단의 `module purge`/`module load`가 주석 처리되지 않은 채로 남아있어 Ubuntu에서 그대로 실행하면 실패. 사용 시 수동 주석 처리 필요.
- `clear.sh`는 `set -e`로 시작하므로 빈 디렉토리에서 `rm`이 실패하면 즉시 중단될 수 있음 (현재는 `rm -f` 사용해 안전).
