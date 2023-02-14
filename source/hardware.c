//
// Created by Jonathon Moore on 11/1/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "../headers/structures.h"
#include "../headers/terasic_os_includes.h"
#include "../headers/LCD_Lib.h"
#include "../headers/lcd_graphic.h"
#include "../headers/font.h"

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

// variables for LCD display
void *virtual_base_LCD;
int fd_LCD;
LCD_CANVAS LcdCanvas;

// variables for user button
void *virtual_base_USER_BUTTON;
int fd_USER_BUTTON;
uint32_t scan_input;
volatile int *KEY_ptr;

void * virtual_base;

// variables for lED/FPGA
int open_physical(int);
void * map_physical(int, unsigned int, unsigned int);
void close_physical(int);
int unmap_physical(void *, unsigned int);
volatile unsigned int *JP1_ptr;

int fd = -1;
void *LW_virtual;

/**
 * initialize all hardware and pointers to be used
 */
void initializeHardware()
{

}

/**
 * Will set the output pins to the binary number passed into it
 * @param binary
 * @param size
 */
void setPins(int *binary, int size)
{
    int i, j;
    for (i = 0, j = 5; j >= 0; j--, i++)
    {
        if (i < size)
        {
            printf("setting pin a%d: %d\n", i, binary[size - (i + 1)]);
        }
        else
        {
            printf("setting pin a%d: %d\n", i, 0);
        }
    }
}

/**
 * Sets the add/subtract pin depending on whether they want to decode or not
 */
void setDecode()
{
    printf("setting pin d0 to 1\n");
}

/**
 * Reads the input GPIO pins for the binary number and returns the binary number
 * @param binary
 * @param size
 * @return the binary number from the input pins
 */
int* readPins(int* binary, int size)
{
    int i, j;
    for (i = 0, j = 5; j >= 0; j--, i++)
    {
        if (i < size)
        {
            printf("reading pin a%d: %d\n", i, binary[size - (i + 1)]);
        }
        else
        {
            printf("reading pin a%d: %d\n", i, 0);
        }
    }


    return binary;
}











