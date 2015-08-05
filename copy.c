#include <stdio.h>

// copy input to output version 1
int main()
{
        int c;

        c = getchar();
        while (c != EOF) {
                putchar(c);
                c = getchar();
        }
}

// copy input to output version 2
void main2()
{
        int c;

        while ((c = getchar()) != EOF) {
                putchar(c);
        }
}
