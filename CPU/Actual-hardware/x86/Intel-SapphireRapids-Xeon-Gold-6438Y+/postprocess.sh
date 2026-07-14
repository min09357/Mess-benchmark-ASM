# #!/bin/bash



export ROOT_DIR="$(pwd)"
export OUTPUT_DIR="${ROOT_DIR}/measuring/${OUTPUT}"


# ./create_runner_config.sh config/sapphireRapids_ddr5.toml 
# cp ./config.sh ${OUTPUT_DIR}


PROCESSING_DIR="${ROOT_DIR}/processing/"
${PROCESSING_DIR}/main.py ${OUTPUT_DIR}