#include <stdio.h>

// count digits, whitespace and others
int main()
{
        int c, i, n_white, n_other;
        int n_digits[10];

        n_white = n_other = 0;

        // zero the array
        for (i = 0; i < 10; ++i)
                n_digits[i] = 0;

        while ((c = getchar()) != EOF)
                if (c >= '0' && c <= '9')
                        ++n_digits[c - '0'];
                else if (c == ' ' || c == '\n' || c == '\t')
                        ++n_white;
                else
                        ++n_other;

        printf("digits:");
        for (i = 0; i < 10; ++i)
                printf(" %d", n_digits[i]);
        printf(", whitespace: %d, other: %d\n", n_white, n_other);
}
