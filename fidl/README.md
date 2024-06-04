# What is Commonapi?
CommonAPI C++ is a C++ framework designed for internal process communication. It consists of high-level C++ APIs and can be used with various IPC mechanisms like D-Bus and SOME/IP. 
Its features include:

- Adapting application code to specific IPCs through CommonAPI bindings.
- Current support for D-Bus (libdbus) and SOME/IP.
- Franca IDL base code generator (currently supports Franca 0.9.1).
- High-performance implementation utilizing C++ templates.

You can find the installation documentation and example code for CommonAPI at this link. It's very useful.   
[CommonAPI C++ SomeIP in 10 minutes](https://github.com/COVESA/capicxx-someip-tools/wiki/CommonAPI-C---SomeIP-in-10-minutes)

## Commonapi Core and Binding Library
<img src="https://github.com/SEA-ME-Team6/DES_Head-Unit/assets/119277948/9eb817b7-50cf-4363-be65-9716517d573e">

  ### Key Point
  CommonAPI C++ has a structure that, when an application implements a specific function using a shared library, it is linked only to the CommonAPI runtime and the generated C++ code, and not to binding-specific code. 
  This allows libraries required for specific bindings, such as D-Bus or SOME/IP glue code, to be loaded dynamically at runtime. 

  The connection between CommonAPI core and binding shared libraries is established through the commonapi.ini file, during runtime, not at compile time.
  
  **This is the standard CommonAPI way to connect to D-Bus or SOME/IP**
  
  Therefore, each application does not contain any code related to SOME/IP binding. Instead, shared libraries related to binding are created in the top-level CMakeLists.txt file.

## SOME/IP communication patterns for each service
- Gear : Both of Method, Attribute
- Light : Attribute having Two instances
- Moving : Attribute including Throttle, Steering
- RPM : Attribute
- Batterty : Attribute

## Reference
[Welcome to the CommonAPI C++ wiki!](https://github.com/COVESA/capicxx-core-tools/wiki)

[GENIVI CommonAPI](https://medium.com/@aytackahveci93/introduction-to-genivi-commonapi-640472f468e)

[vsomeip](https://github.com/COVESA/vsomeip/wiki/vsomeip-in-10-minutes)
