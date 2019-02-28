#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "cpu.h"
#include "ram.h"
#include "pcb.h"


//Ready queue
struct node {
    struct PCB * val;
    struct node *next;
};
struct node * head;
struct node * tail;



void addToReady(struct PCB * program_pcb){

    if(head == NULL){
        head = malloc(sizeof(struct node));
        head->val = program_pcb;
        head->next = NULL;
        tail=head;
    }else{
        struct node *new_node = malloc(sizeof(struct node));
        new_node->val=program_pcb;
        tail->next=new_node;
        tail=new_node;
        if(head->next == NULL){
            head->next=tail;
        }

    }
}



void scheduler(){
    int memory_index=0;
    FILE * midwayFilePointer;

    while(head !=NULL) {
        if (cpu->IP == NULL || cpu->quanta == 0) {
            struct PCB *file_pcb = head->val;
            cpu->IP = file_pcb->PC;
            cpu->quanta = 2;
            midwayFilePointer = run(cpu->quanta);

            //if not EOF
            if (midwayFilePointer != NULL) {
                head->val->PC = midwayFilePointer;
                struct node *temp = head;

                if(head->next == NULL){
                    continue;
                }
                head = head->next;
                tail->next = temp;
                temp->next = NULL;
                tail = temp;
            } else {
                while (ram->memory[memory_index] != head->val->PC) {
                    memory_index++;
                }

                ram->memory[memory_index] = NULL;


                struct PCB *old_pcb = head->val;
                struct node *old_node = head;
                head = head->next;
                free(old_node);
                free(old_pcb);
                cpu->IP=NULL;

//                if(head == tail){
//                    free(tail);
//                }

            }
        }
    }
}






// myinit(FILE *p) which does the following:
// 1. It calls void addToRAM(FILE *p) from ram.c to add the file pointer to the next available
// cell in ram[].
// 2. It calls PCB* makePCB(FILE *p) from pcb.c to create a PCB instance using malloc.
// 3. It calls void addToReady(PCB *) from kernel.c to add the PCB to the tail of the Ready
// Queue
void myinit(FILE *p){
    addToRAM(p);
    struct PCB * file_pcb = makePCB(p);
    addToReady(file_pcb);
}







//need to handle multiple files of identical name
//

int main (int argc, char * argv []){
    cpu=malloc(sizeof(struct CPU));
    cpu->quanta=2;

    ram = malloc(sizeof(struct RAM));
    printf("\nKernel 1.0 loaded!\n");
    shell(argc,argv);
    free(cpu);
    free(ram);
    return 0;
}