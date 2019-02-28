//
// Created by twong on 2/26/19.
//

#ifndef KERNEL_RAM_H
#define KERNEL_RAM_H

void addToRAM(FILE *p);

struct RAM
{
    FILE *memory[10];
};

struct RAM *ram;

#endif //KERNEL_RAM_H
