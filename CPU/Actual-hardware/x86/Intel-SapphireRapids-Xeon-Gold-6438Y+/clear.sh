set -e

rm -f measuring/bw/*.txt measuring/lat/*.txt measuring/log/*.log measuring/output/*.csv measuring/output/*.pdf src/ptr_chase/*.dat

rm -rf measuring/output/curves


cd src/ptr_chase && make clean

cd ../RandomAccess_hpcc && make clean

cd ../stream_mpi && make clean

