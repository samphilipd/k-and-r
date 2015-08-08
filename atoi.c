#include <stdio.h>

#define MAX_LEN 9 // remove any possibility of overflow

int atoi(char s[]);

int main()
{
        char c;
        char s[MAX_LEN];
        int len = 0;

        while ((c = getchar()) != EOF && len <= MAX_LEN) {
                s[len++] = c;
        }

        printf("Parsed number was: %d\n", atoi(s));

        return 0;
}

// atoi: convert ASCII string into integer
// it is possible to parse strings to integers in most languages because a string
// character is just a number represenation underneath anyway
int atoi(char s[])
{
        int i, n;

        n = 0;
        for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
                n = 10 * n + (s[i] - '0');
        return n;
}
