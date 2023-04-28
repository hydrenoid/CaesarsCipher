/**
 * Created by Jonathon Moore
 * SWE-450
 * Professor Mark
 *
 * This module is the header file for all connections to the board.
 */
#include "structures.h"
#ifndef UNTITLED2_HARDWARE_H

// extern because it is used in another module
extern int initializeHardware();
extern int closeResources();
void setupParallelPort();
extern void setPins(int input);
extern int readPins();

#define UNTITLED2_HARDWARE_H

#endif //UNTITLED2_HARDWARE_H
