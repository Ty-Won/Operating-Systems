#include <stdio.h>
#include <stdlib.h>

struct PCB{
    FILE *PC;
};




struct PCB* makePCB(FILE *p){
    struct PCB * program_pcb;
    program_pcb = malloc(sizeof(struct PCB));
    program_pcb->PC=p;
    return program_pcb;
}