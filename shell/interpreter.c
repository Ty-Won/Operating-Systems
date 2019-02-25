#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "shell.h"
#include "shellmemory.h"



void help() {
    printf("COMMAND\t\t\t\tDESCRIPTION\n"
                   "help\t\t\t\tDisplays all the commands\n"
                   "quit\t\t\t\tExits / terminates the shell with \"Bye\"\n"
                   "set VAR STRING\t\t\tAssigns a value to shell memory\n"
                   "print VAR\t\t\tPrints the STRING assigned to VA\n"
                   "run SCRIPT.TXT\t\t\tExecutes the file SCRIPT.txt\n"
    );
}


int run(char *file) {
    int errCode = 0;
    char line[1000];

    FILE *p = fopen(file, "r");
    if (p == NULL) {
        printf("Error: No file found\n");
        return 0;
    }
    fgets(line, 999, p);
    while (!feof(p)) {
        errCode = parse(line);
        if (errCode != 0) {
            return errCode;
        }
        fgets(line, 999, p);
    }

    return 0;
}


int quit() {
    printf("Bye!\n");
    return -1;
}


int interpreter(char *words[]) {
    int errCode = 0;

    if (strcmp(words[0], "help") == 0) {
        help();
    } else if (strcmp(words[0], "quit" ) == 0 ) {
        errCode = quit();
    } else if (strcmp(words[0], "set" ) == 0) {
        set(words[1], words[2]);

    } else if (strcmp(words[0], "print") == 0) {
        print_var(words[1]);
    } else if (strcmp(words[0], "run") == 0) {
        errCode = run(words[1]);
    } else {
        printf("Command not found or too many arguments\n");
    }

    return errCode;
}