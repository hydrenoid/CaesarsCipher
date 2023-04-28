/**
 * Created by Jonathon Moore
 * SWE-450
 * Professor Mark
 *
 * This module defines the structures for the parallel port as well as the directional port along with it.
 * For the directional port 1 means write and 0 means read.
 */
#ifndef SWE_450MILESTONE2_STRUCTURES_H


typedef struct{
    unsigned int data_register_operand_1 : 8;
    unsigned int data_register_operand_2 : 8;
    unsigned int data_register_unused : 16;
}PARALLEL_PORT_DR;

typedef struct{
    unsigned int data_register_operand_1 : 8;
    unsigned int data_register_operand_2 : 8;
    unsigned int data_register_unused : 16;
}PARALLEL_PORT_DIR;


#define SWE_450MILESTONE2_STRUCTURES_H

#endif //SWE_450MILESTONE2_STRUCTURES_H
