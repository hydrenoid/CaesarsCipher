/**
 * Created by Jonathon Moore
 * SWE-450
 * Professor Mark
 *
 * This module handles all connection to the board and pins.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "structures.h"
#include "terasic_os_includes.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "hwlib.h"
#include "socal/socal.h"
#include "socal/hps.h"
#include "socal/alt_gpio.h"
#include "address_map_arm.h"
#include <sys/mman.h>

#define HW_REGS_BASE ( ALT_STM_OFST )
#define HW_REGS_SPAN ( 0x04000000 )
#define HW_REGS_MASK ( HW_REGS_SPAN - 1 )

#define USER_IO_DIR     (0x01000000)
#define BIT_LED         (0x01000000)
#define BUTTON_MASK     (0x02000000)


// Pointer to ParallelPort Bit Structure, directional port, virtual base
PARALLEL_PORT_DR* jp1_port;
PARALLEL_PORT_DIR* dir_port;
void *virtBase;
int f_d;

volatile unsigned int *JP1_ptr;


/**
 * initialize all hardware and pointers to be used
 * @return Success in int form
 */
int initializeHardware()
{
    if((f_d = open("/dev/mem", (O_RDWR | O_SYNC))) == -1){
        printf("ERROR: Could not Open...");
        return (-1);
    }

    virtBase = mmap(NULL, LW_BRIDGE_SPAN, (PROT_READ | PROT_WRITE), MAP_SHARED, f_d, LW_BRIDGE_BASE);
    if(virtBase == MAP_FAILED){
        printf("ERROR: mmap() failed...");
        close(f_d);
        return (NULL);
    }

}


/**
 * Close the hardware connection to the board pins
 * @return an int representing successful closure
 */
int closeResources(){

    if(munmap (virtBase, LW_BRIDGE_SPAN) != 0){
        printf("ERROR: munmap failed...");
        return(-1);
    }
    close(f_d);
    return 0;
}


/**
 * Function to assign the Base address of the JP1 Port to the Parallel Port Variable
 * @param virtualBase
 * @param fd
 */
void setupParallelPort(){

    jp1_port = (unsigned int *)(virtBase + JP1_BASE);

    dir_port = (unsigned  int *)(jp1_port +1);
    dir_port ->data_register_operand_1 = 0x00FF;
    dir_port ->data_register_operand_2 = 0x0000;
    dir_port ->data_register_unused = 0;
}


/**
 * Will set the output pins to the binary number passed into it
 * @param binary
 * @param size
 */
void setPins(int input)
{
    jp1_port->data_register_operand_1 = input;
}


/**
 * Reads the input GPIO pins for the binary number and returns the binary number
 * @param binary
 * @param size
 * @return the binary number from the input pins
 */
int readPins()
{
    int output = jp1_port->data_register_operand_2;

    return output;
}
