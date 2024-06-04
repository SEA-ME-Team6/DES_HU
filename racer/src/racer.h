#ifndef RACER_H
#define RACER_H

#define PY_SSIZE_T_CLEAN
#include "IncludePython.h"

class Racer
{
public:
    Racer();
    ~Racer();

    void set_steering_percent(float currentsteering);
    void set_throttle_percent(float currentthrottle);

private:
    PyObject *pModule, *pClass, *pInstance;

};

#endif //Racer_H
