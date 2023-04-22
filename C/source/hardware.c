//
// Created by Jonathon Moore on 11/1/2022.
//
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

#define TRUE ( 1 )
#define FALSE ( 0 )


void * virtual_base;

PARALLEL_PORT_DR* jp1_port;//Pointer to ParallelPort Bit Structure
PARALLEL_PORT_DIR* dir_port;
void *virtBase;
int f_d;

// variables for lED/FPGA
int open_physical(int);
void * map_physical(int, unsigned int, unsigned int);
void close_physical(int);
int unmap_physical(void *, unsigned int);
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
int closeResources(void *virtualBase, int fd){

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
void setupParallelPort(void *virtualBase, int fd){

    jp1_port = (unsigned int *)(virtBase + JP1_BASE);
    //*(jp1_port +1)  = 0x000F;

    dir_port = (unsigned  int *)(jp1_port +1);
    dir_port ->data_register_operand_1 = 0x000F;
    dir_port ->data_register_operand_2 = 0x000F;
    dir_port ->data_register_operand_3 = 0x000F;
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


//    int i, j;
//    for (i = 0, j = 7; j >= 0; j--, i++)
//    {
//        if (i < size)
//        {
//            printf("setting pin a%d: %d\n", i, binary[size - (i + 1)]);
//        }
//        else
//        {
//            printf("setting pin a%d: %d\n", i, 0);
//        }
//    }
}

/**
 * Sets the add/subtract pin depending on whether they want to decode or not
 */
void setDecode(int toDecode)
{
    printf("setting pin d0 to 1\n");
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
