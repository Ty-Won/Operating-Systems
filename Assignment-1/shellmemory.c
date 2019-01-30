#include <malloc.h>

typedef struct shellmemory {
    char *variable;
    char *value;
    struct shellmemory *next;
} SHELLMEMORY;

SHELLMEMORY *head;

void set(char var[], char val[]) {
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
            if(temp->next==NULL){
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
    while (temp != NULL) {
        if (*((char*)(temp->variable)) == *var) {
            printf("%s\n", temp->value);
            return;
        } else {
            temp = temp->next;
        }
    }
    printf("Error no variables found\n");
}