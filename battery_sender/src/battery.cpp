#include "battery.h"
#include <iostream>

Battery::Battery() {
    Py_Initialize();
    pModule = PyImport_ImportModule("piracer.vehicles"); 
    pClass = PyObject_GetAttrString(pModule, "PiRacerStandard");
    pInstance = PyObject_CallObject(pClass, NULL);
}

Battery::~Battery() {
    Py_XDECREF(pVoltage);
    Py_XDECREF(pInstance);
    Py_XDECREF(pClass);
    Py_XDECREF(pModule);
    Py_FinalizeEx();
}

uint32_t Battery::get_battery_voltage() {
    pVoltage = PyObject_CallMethod(pInstance, "get_battery_voltage", NULL);
    voltage = PyFloat_AsDouble(pVoltage);
    batteryStatus = (uint32_t)(voltage * 100); 
    return batteryStatus;
}
