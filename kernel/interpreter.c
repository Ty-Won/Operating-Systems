#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "shell.h"
#include "shellmemory.h"
#include "kernel.h"

void help()
{
    printf("COMMAND\t\t\t\tDESCRIPTION\n"
           "help\t\t\t\tDisplays all the commands\n"
           "quit\t\t\t\tExits / terminates the shell with \"Bye\"\n"
           "set VAR STRING\t\t\tAssigns a value to shell memory\n"
           "print VAR\t\t\tPrints the STRING assigned to VA\n"
           "run SCRIPT.TXT\t\t\tExecutes the file SCRIPT.txt\n");
}

int run_script(char *file)
{
    int errCode = 0;
    char line[1000];

    FILE *p = fopen(file, "r");
    if (p == NULL)
    {
        printf("Error: No file found\n");
        return 0;
    }

    while (fgets(line, 999, p))
    {
        errCode = parse(line);
        if (errCode != 0)
        {
            return errCode;
        }
    }
    fclose(p);
    return 0;
}

int exec(char *words[], int num_of_args){

    int num_of_files = num_of_args-1;
    int i=1;
    switch (num_of_files)
    {
        case 1:
            break;
        case 2:
            if(strcmp(words[1],words[2])==0){
                printf("Error: Script %s already loaded\n",words[2]);
                num_of_files--;
            }
            break;
        case 3:
            if(strcmp(words[1],words[2])==0){
                printf("Error: Script %s already loaded\n",words[1]);
                i++;
            }else if(strcmp(words[1],words[3])==0){
                printf("Error: Script %s already loaded\n",words[1]);
                i++;
            }else if(strcmp(words[2],words[3])==0){
                printf("Error: Script %s already loaded\n",words[2]);
                num_of_files--;
            }
            break;
        default:
            printf("Error:Too many program args\n");
            return 0;
    }


    for (i;i<num_of_files+1;i++){


        FILE * exec_file = fopen(words[i], "r");
        if (exec_file == NULL)
        {
            printf("Error: Could not locate %s\n",words[i]);
            if(num_of_files>1){
                continue;
            }
            return 0;
        }else{
            //comes from kernel
            myinit(exec_file);
        }
        //fclose(exec_file);
    }
    scheduler();
    return 0;

}



int quit()
{
    printf("Bye!\n");
    return -1;
}



int interpreter(char *words[], int num_of_args)
{
    int errCode = 0;

    if (strcmp(words[0], "help") == 0)
    {
        help();
    }
    else if (strcmp(words[0], "quit") == 0)
    {
        errCode = quit();
    }
    else if (strcmp(words[0], "set") == 0)
    {
        set(words[1], words[2]);
    }
    else if (strcmp(words[0], "print") == 0)
    {
        print_var(words[1]);
    }
    else if (strcmp(words[0], "run") == 0)
    {
        errCode = run_script(words[1]);
    }
    else if (strcmp(words[0], "exec") == 0)
    {
        errCode = exec(words,num_of_args);
    }
    else
    {

        printf("Command not found or too many arguments\n");
    }

    return errCode;
}