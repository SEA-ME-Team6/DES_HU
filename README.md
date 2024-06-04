# DES_Head-Unit

## Introduction
This project aims to implement a Vehicle Application based on Service-Oriented Architecture (SOA). Each application communicates through the Someip protocol. This project utilize Commonapi to design the communication structure.
And, the Head Unit includes functions such as music, ambient light, gear selection, and head light. Each of these functions is managed within the Head Unit by the Qt Application Manager

The applications are as follows:
- Head Unit
- Instrument Cluster
- Racer
- RPM Sender
- Battery Sender
- Gamepad

The service are as follows:
- Gear
- Light
- Moving
- RPM
- Battery

## Architecture
<img src="https://github.com/SEA-ME-Team6/DES_Head-Unit/assets/119277948/c43af405-a0d5-4f70-8a0d-dbde340181b0">

## Usage
```
git clone https://github.com/SEA-ME-Team6/DES_Head-Unit.git
cd DES_Head-Unit
mkdir build
cd build
cmake .. && make
```

## Following
  ### [Commonapi Concept](https://github.com/SEA-ME-Team6/DES_Head-Unit/tree/dev-communication/fidl)
  ### [Generate code](https://github.com/SEA-ME-Team6/DES_Head-Unit/tree/dev-communication/src-gen)
  ### [Head Unit](https://github.com/SEA-ME-Team6/DES_Head-Unit/tree/dev-communication/head_unit)
  ### [Instrucment Cluster](https://github.com/SEA-ME-Team6/DES_Head-Unit/tree/dev-communication/instrument_cluster)
  ### [Racer](https://github.com/SEA-ME-Team6/DES_Head-Unit/tree/dev-communication/racer)
  ### [RPM Sender](https://github.com/SEA-ME-Team6/DES_Head-Unit/tree/dev-communication/rpm_sender)
  ### [Battery Sender](https://github.com/SEA-ME-Team6/DES_Head-Unit/tree/dev-communication/battery_sender)
  ### [Gamepad](https://github.com/SEA-ME-Team6/DES_Head-Unit/tree/dev-communication/gamepad)
  
