#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 10

// find: print lines that match pattern from 1st arg
int main(int argc, char * argv[])
{
        size_t nbytes = MAXLINE;
        char *line;
        int found = 0;

        line = (char *) malloc (nbytes+1);

        if (argc != 2)
                printf("Usage: find pattern\n");
        else
                while (getline(&line, &nbytes, stdin) > 0)
                        if (strstr(line, argv[1]) != NULL) {
                                printf("%s", line);
                                ++found;
                        }
        return found;

}
