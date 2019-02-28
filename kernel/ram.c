#include <stdio.h>
#include "ram.h"


void addToRAM(FILE *p){
    int i = 0;

    while (i < 10)
    {
        if (ram->memory[i] != NULL)
        {
            i++;
            continue;
        }
        else
        {
            ram->memory[i] = p;
            printf("Loaded into memory %d \n", i);
            break;
        }
    }

}




