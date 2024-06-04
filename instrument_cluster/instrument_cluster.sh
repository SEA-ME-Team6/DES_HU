#!/bin/sh

# cd build
# make
# cd ..

SCRIPT_DIR=$(dirname "$0")

export COMMONAPI_CONFIG="$SCRIPT_DIR/instrument_cluster.ini"
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/seame-workstation08/dahyun/app-ipi/build/instrument_cluster

# $SCRIPT_DIR/instrument_cluster -platform linuxfb
$SCRIPT_DIR/../build/instrument_cluster/instrument_cluster

