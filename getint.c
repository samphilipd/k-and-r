#include <stdio.h>
#include <ctype.h>

// getint: get next integer from input into *pn
int getint(int *pn)
{
        int c, sign;

        while (isspace(c = getc(stdin))) // skip leading whitespace
                ;
        if (isdigit(c) && c != EOF && c != '+' && c != '-') {
                ungetc(c, stdin); // it isn't a number, spit it back
                return 0;
        }
        sign = (c == '-') ? -1 : 1; // save sign

        if (c == '+' || c == '-')
                c = getc(stdin);

        for (*pn = 0; isdigit(c); c = getc(stdin))
                *pn = 10 * *pn + (c - '0');

        *pn *= sign;
        if (c != EOF)
                ungetc(c, stdin);
        return c;
}
