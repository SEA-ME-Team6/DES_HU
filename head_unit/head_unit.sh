#!/bin/sh

# cd build
# make
# cd ..

SCRIPT_DIR=$(dirname "$0")

export COMMONAPI_CONFIG="/home/seame-workstation08/dahyun/app-ipi/head_unit/head-unit.ini"
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/seame-workstation08/dahyun/app-ipi/build

appman --builtin-apps-manifest-dir ./apps system-ui/system-ui.qml --qml-debug --start-session-dbus  --verbose -r "$@"


