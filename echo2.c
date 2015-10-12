#include <stdio.h>

// echo command-line args using pointer arithmetic
int main(int argc, char * argv[])
{
        while (--argc > 0)
                printf("%s%s\n", *++argv, (argc > 1) ? " " : "");
        printf("\n");
        return 0;
}
