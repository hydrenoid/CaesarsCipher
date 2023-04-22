//
// Created by Jonathon Moore on 11/1/2022.
//

#ifndef SWE_450MILESTONE2_STRUCTURES_H


typedef struct{
    unsigned int data_register_operand_1 : 8;
    unsigned int data_register_operand_2 : 8;
    unsigned int data_register_operand_3 : 1;
    unsigned int data_register_unused : 15;
}PARALLEL_PORT_DR;

typedef struct{
    unsigned int data_register_operand_1 : 8;
    unsigned int data_register_operand_2 : 8;
    unsigned int data_register_operand_3 : 1;
    unsigned int data_register_unused : 15;
}PARALLEL_PORT_DIR;


#define SWE_450MILESTONE2_STRUCTURES_H

#endif //SWE_450MILESTONE2_STRUCTURES_H
