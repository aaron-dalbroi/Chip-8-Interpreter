//
// Created by Aaron on 10/19/2023.
//

#ifndef CHIP8_H
#define CHIP8_H

#include <stdint.h>


typedef struct{

    uint8_t registers[16];
    uint8_t memory[4096];
    uint16_t stack[16];
    uint16_t I;
    /*chip-8 programs start at 0x200, 0x000-0x1ff was where the original interpreter was, so move file ptr there*/
    uint16_t PC;
    uint16_t SP;
    uint8_t delay;
    uint8_t sound;
} chip8;

//Load game into memory from file
void initialize(chip8 game);



#endif