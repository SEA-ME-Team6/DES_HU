#!/bin/sh

# cd build
# make
# cd ..

SCRIPT_DIR=$(dirname "$0")

export COMMONAPI_CONFIG="$SCRIPT_DIR/battery_sender.ini"

$SCRIPT_DIR/../build/battery_sender/battery_sender
# $SCRIPT_DIR/battery_sender

