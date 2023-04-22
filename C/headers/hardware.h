//
// Created by Jonathon Moore on 11/1/2022.
//
#include "structures.h"
#ifndef UNTITLED2_HARDWARE_H


// extern because it is used in another module
extern int initializeHardware();
extern int closeResources(void *virtualBase, int fd);
void setupParallelPort(void *virtualBase, int fd);
extern void setPins(int input);
extern int readPins();
extern void setDecode(int toDecode);

#define UNTITLED2_HARDWARE_H

#endif //UNTITLED2_HARDWARE_H
