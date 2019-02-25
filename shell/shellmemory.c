#include <malloc.h>
#include <memory.h>

typedef struct shellmemory {
    char *variable;
    char *value;
    struct shellmemory *next;
} SHELLMEMORY;

SHELLMEMORY *head;

void set(char var[], char val[]) {
    if(val == NULL){
        printf("Did not set variable: Error\n");
        return;
    }

    if (head == NULL) {
        head = malloc(sizeof(SHELLMEMORY));
        head->value = val;
        head->variable = var;
        head->next = NULL;
    } else {
        SHELLMEMORY *temp = head;
        SHELLMEMORY *newNode = malloc(sizeof(SHELLMEMORY));
        newNode->variable = var;
        newNode->value = val;
        newNode->next = NULL;
        while(temp!= NULL){
            if(strcmp((temp->variable), var)==0 ){
                temp->value=val;
                break;
            }
            else if(temp->next==NULL){
                temp->next=newNode;
                break;
            }
            else {
                temp = temp->next;
            }
        }

    }
    printf("Variable Set\n");

}

void print_var(char var[]) {
    SHELLMEMORY *temp = head;
    if(var == NULL){
        printf("Error no variables found\n");
    }

    while (temp != NULL) {

        if(strcmp((temp->variable), var) == 0){
            printf("%s\n", temp->value);
            return;
        } else {
            temp = temp->next;
        }
    }
    printf("Error no variables found\n");
}