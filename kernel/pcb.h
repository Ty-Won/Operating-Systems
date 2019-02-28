//
// Created by twong on 2/26/19.
//

#ifndef KERNEL_PCB_H
#define KERNEL_PCB_H
struct PCB{
    FILE *PC;
};
struct PCB* makePCB(FILE *p);
#endif //KERNEL_PCB_H
