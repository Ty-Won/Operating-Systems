#include <stdio.h>
#include <string.h>
#include "interpreter.h"


int parse(char userInput[])
{
    char tmp[200];
    char *words[1000];
    int a, b;
    int w = 0;

    //Scan over the left most character to handle if it is blank
    for (a = 0; userInput[a] == ' ' && a < 1000; a++)
    {
        // while (userInput[a] != '\0' && a < 1000)

        //If the input is not preceeded by blank, iterate over the rest of input as long as its less than 1000
        // and not equal to end of string
        while (userInput[a] != '\0' && a < 1000)
        {
            for (b = 0; userInput[a] != '\0' && userInput[a] != ' ' && a < 1000; a++, b++)
            {
                tmp[b] = userInput[a];
            }
            tmp[b] = '\0';
            words[w] = strdup(tmp);
            a++;
        }
    }
   
    return interpreter(words);
}


int main()
{
    char prompt[100] = {'$', '\0'};
    char userInput[1000];
    int errorCode = 0;
    printf("Welcome to the Tyrone Shell! \nVersion 1.0 Created January 2019\n");
    
    do
    {
        printf("%s", prompt);
        fgets(userInput, 999, stdin);
        errorCode = parse(userInput);  
    } while (errorCode);
}