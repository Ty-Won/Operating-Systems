#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "shell.h"
#include "shellmemory.h"

int script(char *words[]) {
    int errCode = 0;
    char line[1000];
    FILE *p = fopen(words[0], "rt");

    fgets(line, 999, p);

    while (!feof(p)) {
        errCode = parse(line);
        if (errCode != 0) {
            return errCode;
        }
        fgets(line, 999, 0);
    }
    return errCode;
}


void help() {
    printf("COMMAND\tDESCRIPTION\n"
                   "help\tDisplays all the commands\n"
                   "quit\tExits / terminates the shell with \"Bye\"\n"
                   "set VAR STRING\tAssigns a value to shell memory\n"
                   "print VAR\t\"Prints the STRING assigned to VA\"\n"
                   "run SCRIPT.TXT\tExecutes the file SCRIPT.txt\n"
    );
}


int run(char script[]) {
    return 0;
}

int quit() {
    printf("Bye");
    return -1;
}


int interpreter(char *words[]) {
    int errCode = 0;

    if (*(words[0]) == '.' && *(words[0] + 1) == '/') {
        errCode = script(words);
    } else if (strcmp(words[0], "help") == 0) {
        help();
    } else if (strcmp(words[0], "quit") == 0) {
        errCode = quit();
    } else if (strcmp(words[0], "set") == 0) {
        set(words[1], words[2]);

    } else if (strcmp(words[0], "print") == 0) {
        print_var(words[1]);
    } else if (strcmp(words[0], "run") == 0) {
        errCode = run(words[1]);
    } else {
        printf("Command not found or too many arguments");
    }

    return errCode;
}