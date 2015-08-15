#include <stdio.h>

int main()
{
        int c, blanks;

        blanks = 0;
        while ((c = getchar()) != EOF)
                if (c == ' ' || c == '\t' || c == '\n')
                        blanks++;
        printf("%d\n", blanks);
}
