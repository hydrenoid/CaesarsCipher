//
// Created by Jonathon Moore on 11/1/2022.
//
#include "structures.h"
#ifndef UNTITLED2_HARDWARE_H


// extern because it is used in another module
extern void initializeHardware();
extern void setPins(int *binary, int size);
extern int* readPins(int *binary);
extern void setDecode();

#define UNTITLED2_HARDWARE_H

#endif //UNTITLED2_HARDWARE_H
