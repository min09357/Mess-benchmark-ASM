# 수정사항

## src/stream_mpi/Makefile

MPICC = mpicc   (원본 icx는 슈퍼컴 전용)
MPI_LIB =
MPI_INCLUDE =

export MPICH_CC = /usr/bin/gcc (아나콘다 환경에서 충돌이 있나봄)

## src/ptr_chase/Makefile

shell bc <<< ...가 Ubuntu의 /bin/sh = dash에서 실패.

SHELL := /bin/bash 추가

## submit_main.job

SBATCH, module 주석처리

launch_stream() 에서 srun을 mpirun으로 교체

terminate_stream, sleep 주석제거

trap 'pkill -P $$ -SIGKILL mpirun 2>/dev/null; pkill -SIGKILL stream_mpi.x 2>/dev/null' EXIT 추가

export LC_ALL=C 추가 (perf가 컴마를 찍음)

## runner.sh

메인루프에서 sbatch를 bash로 변경 및 squeue 대기 루프 제거

postprocess 활성화(주석제거)

export TIME_AFTER_STREAM_TERMINATION=${TIME_AFTER_STREAM_TERMINATION} 추가

## ptr_chase.c

line 65에서 원래

struct line *array;

였는데 using namespace std 때문에 std::array와 ambiguity

따라서 struct line *array; → struct line *mess_array; 를 하고 변수명 전부 바꿈

## arraygen.c

마찬가지 line 55에 

struct line *array; → struct line *mess_array;

이후 나머지 변수명 전부 바꿈

## calculator.py

r1012와 r2012가 반대로 쓰임.

SPR perf core event에서 

r1012(event code: 0x12, Umask: 0x10)는 page walk cycles, r2012(event code: 0x12, Umask: 0x20)는 STLB hit 횟수