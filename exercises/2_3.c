#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 11

int htoi(char s[]);

int main()
{
        char c;
        char s[MAX_LEN + 1];
        int len = 0;

        while ((c = getchar()) != EOF && len <= MAX_LEN) {
                s[len++] = c;
        }
        s[len] = '\0';

        printf("Parsed number was: %d\n", htoi(s));

        return 0;
}

// atoi: parse ASCII string of Hex digits into integer. initial 0x is optional
// WARNING: overflow is possible for large inputs
int htoi(char s[])
{
        int i, start_hex = 0, n = 0;

        // look for the hex start string
        if (s[0] == '0' && tolower(s[1]) == 'x') {
                start_hex = 2;
        }

        for (i = start_hex; s[i] != '\0'; ++i) {
                if (isdigit(s[i])) {
                        n = n * 16 + s[i] - '0';
                } else {
                        char try_hex = tolower(s[i]) - 'a';
                        if (try_hex >= 0 && try_hex < 6) {
                                n = n * 16 + (10 + try_hex);
                        }
                }
        }

        return n;
}
