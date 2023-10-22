#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "chip8.h"


void initialize(chip8 game){
    FILE* file = fopen("Cave.ch8","rb");    //read bytes of file

    if(file == NULL){
        perror("Game file could not be opened");
        exit(EXIT_FAILURE);
    }
    /*Determine how large the game file is, and read it into memory*/

    fseek(file,0,SEEK_END);
    int bytesToReadIn = ftell(file);

    if(bytesToReadIn > 4096){
        perror("Game file too large: Max size of 4 KB");
        exit(EXIT_FAILURE);
    }

    //reset file pointer to the beginning of the file
    fseek(file,0,SEEK_SET);

    //read into memory of game
    int bytesReadIn = fread(&game.memory,1,bytesToReadIn,file);

    if(bytesToReadIn != bytesReadIn){
        perror("Failed to read game into memory");
        exit(EXIT_FAILURE);
    }
    fclose(file);

}