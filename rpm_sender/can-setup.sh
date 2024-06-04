#!/bin/sh

# Set Can Interface
ip link set can0 up type can bitrate 500000

# Set txqueuelen
ifconfig can0 txqueuelen 65536
