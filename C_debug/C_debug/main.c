#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACKVALUE 100

static double stack[STACKVALUE];
static double *pStack = stack; /* next free position in stack */

void push(double value) {
        if(pStack - stack > STACKVALUE) {
                printf("error: there is not enough space in stack");
        }
        else {
                *(pStack++) = value;
        }
}

double pop(void) {
        if((pStack - stack) > 0) {
                return *--pStack;
        }
        
        printf("warning: stack is empty");
        return 0.0;
}

double peek(void) {
        return *(pStack - 1);
}

#define MAXLINELEN 100
#define DELIM " "

// expr: a reverse polish calculator
// example: expr 2 3 4 + * => 2 x (3+4) => 14
// naiive version, does no error checking on input
int main()
{
        size_t nbytes = MAXLINELEN;
        char * line;
        
        line = (char *) malloc (nbytes + 1);
        
        double first;
        double second;
        
        while(getline(&line, &nbytes, stdin)) {
                char * token;
                token = strtok(line, DELIM);
                while (token != NULL) {
                        switch (*token) {
                                case '+':
                                        first = pop();
                                        second = pop();
                                        push(second + first);
                                        break;
                                default:
                                        push(atof(token));
                                        break;
                        }
                        token = strtok(NULL, DELIM);
                }
                printf("%f\n", peek());
        }
}
