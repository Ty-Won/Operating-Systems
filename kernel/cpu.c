#include <memory.h>
#include "stdio.h"
#include "cpu.h"
#include "shell.h"


FILE *run(int quanta) {

    int eof_flag = 0;

    for (int line = 0; line < quanta; quanta--) {
        cpu->quanta--;//worry
        char*retrieved_line = fgets(cpu->IR, sizeof(cpu->IR),cpu->IP);
        if (retrieved_line ==NULL) {
            eof_flag = 1;
            break;
        }
        parse(cpu->IR);
    }
    memset(cpu->IR, 0, 255);

    //Not the end of file
    if (eof_flag == 0) {
        return cpu->IP;
    } else {
        return NULL;
    };
}

