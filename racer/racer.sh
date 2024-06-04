#!/bin/sh

# cd build
# make
# cd ..

SCRIPT_DIR=$(dirname "$0")
 
export COMMONAPI_CONFIG="$SCRIPT_DIR/racer.ini"
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/seame-workstation08/dahyun/app-ipi/build/racer


# $SCRIPT_DIR/racer
$SCRIPT_DIR/../build/racer/racer

