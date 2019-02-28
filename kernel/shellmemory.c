#include <malloc.h>
#include <memory.h>

typedef struct shellmemory {
    char *variable;
    char *value;
    struct shellmemory *next;
} SHELLMEMORY;

SHELLMEMORY *head_shell;

void set(char var[], char val[]) {
    if(val == NULL || strcmp(val," ")==0 || strcmp(val,"")==0 || strcmp(val,"\n")==0){
        printf("Did not set variable: Error\n");
        return;
    }

    if (head_shell == NULL) {
        head_shell = malloc(sizeof(SHELLMEMORY));
        head_shell->value = val;
        head_shell->variable = var;
        head_shell->next = NULL;
    } else {
        SHELLMEMORY *temp = head_shell;
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

}

void print_var(char var[]) {
    SHELLMEMORY *temp = head_shell;
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