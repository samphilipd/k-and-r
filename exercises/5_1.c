#include <stdio.h>
#include <ctype.h>

int getint(int *pn);

int main()
{
        int n;

        getint(&n);

        printf("integer: %d\n", n);

        char c = getc(stdin);
        printf("next char: %c", c);

        return 0;
}

// getint: get next integer from input into *pn
// ungetc() doesn't work as expected here because it only guarantees one character
// of pushback.
int getint(int *pn)
{
        int c, sign;
        unsigned numbers_seen = 0;
        char sign_c = 0;

        while (isspace(c = getc(stdin))) // skip leading whitespace
                ;
        if (isdigit(c) && c != EOF && c != '+' && c != '-') {
                ungetc(c, stdin); // it isn't a number, spit it back
                return 0;
        }
        sign = (c == '-') ? -1 : 1; // save sign

        if (c == '+' || c == '-') {
                sign_c = c;
                c = getc(stdin);
        }

        for (*pn = 0; isdigit(c); c = getc(stdin)) {
                *pn = 10 * *pn + (c - '0');
                ++numbers_seen;
        }

        if (sign_c && numbers_seen == 0)
                ungetc(sign_c, stdin); // no numbers followed '-' or '+', push it back
        else if (c != EOF)
                ungetc(c, stdin); // else push back whatever else we got, usually a newline

        *pn *= sign;

        return c;
}
