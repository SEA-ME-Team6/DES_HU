# How to generate code?

# File System

This is recommended file system for generated files in CommonAPI

<img src="https://github.com/SEA-ME-Team6/DES_Head-Unit/assets/119277948/c3c2e363-3427-4cbd-a7f0-f1b3678abca5">

Proxy code is needed by clients, stub code by services, and common code by all users. 
Skeleton code is kept in a separate library to allow for implementing stubs without default inheritance. It's advisable to keep D-Bus and SOME/IP code in distinct libraries.

Call the code generator as follows in order to get the different subdirectories
```
$ <.>/commonapi-generator/commonapi-generator-linux-x86 --skel --dest-common ./src-gen/core/common --dest-proxy ./src-gen/core/proxy --dest-stub ./src-gen/core/stub --dest-skel ./src-gen/core/skel ./fidl/HelloWorld.fidl
$ <.>/commonapi_dbus_generator/commonapi-dbus-generator-linux-x86 --dest-common ./src-gen/dbus/common --dest-proxy ./src-gen/dbus/proxy --dest-stub ./src-gen/dbus/stub ./fidl/HelloWorld.fidl
$ <.>/commonapi_someip_generator/commonapi-someip-generator-linux-x86 --dest-common ./src-gen/someip/common --dest-proxy ./src-gen/someip/proxy --dest-stub ./src-gen/someip/stub ./fidl/HelloWorld.fdepl
```
