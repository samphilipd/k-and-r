#include <stdio.h>

int main()
{
        int c, put_space;

        put_space = 1;

        while ((c = getchar()) != EOF) {
                if (c != ' ') {
                        putchar(c);
                        put_space = 0;
                }
                if (c == ' ') {
                        if (put_space != 1) {
                                putchar(c);
                                put_space = 1;
                        }
                }
        }
}
