//
// Created by twong on 2/26/19.
//

#ifndef KERNEL_CPU_H
#define KERNEL_CPU_H

#include <stdlib.h>

struct CPU {
    FILE * IP;
    //Stored instruction that will be sent
    //to interpreter() for execution
    char IR[1000];

    //assume 2 lines per quanta
    int quanta;
};

struct CPU *cpu;
FILE * run(int quanta);

#endif //KERNEL_CPU_H
