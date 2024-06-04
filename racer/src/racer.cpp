#include "racer.h"
#include <iostream>

Racer::Racer() {
    Py_Initialize();
    pModule = PyImport_ImportModule("piracer.vehicles");
    pClass = PyObject_GetAttrString(pModule, "PiRacerStandard");
    pInstance = PyObject_CallObject(pClass, NULL);
}

Racer::~Racer() {
    Py_XDECREF(pInstance);
    Py_XDECREF(pClass);
    Py_XDECREF(pModule);
    Py_FinalizeEx();
}

void Racer::set_steering_percent(float currentsteering){
    std::cout << "piracer set steering: " << currentsteering << std::endl;
    PyObject_CallMethod(pInstance, "set_steering_percent", "(f)", currentsteering);
}

void Racer::set_throttle_percent(float currentthrottle){
    std::cout << "piracer set throttle: " << currentthrottle << std::endl;
    PyObject_CallMethod(pInstance, "set_throttle_percent", "(f)", currentthrottle);
}
