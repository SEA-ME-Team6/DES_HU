#!/bin/sh

ip link set can0 up type can bitrate 500000 

SCRIPT_DIR=$(dirname "$0")

export COMMONAPI_CONFIG="$SCRIPT_DIR/rpm_sender.ini"

# $SCRIPT_DIR/rpm_sender
$SCRIPT_DIR/../build/rpm_sender/rpm_sender

