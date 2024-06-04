#!/bin/sh

# cd build
# make
# cd ..

SCRIPT_DIR=$(dirname "$0")

export COMMONAPI_CONFIG="$SCRIPT_DIR/gamepad.ini"

$SCRIPT_DIR/../build/gamepad/gamepad
# $SCRIPT_DIR/gamepad

