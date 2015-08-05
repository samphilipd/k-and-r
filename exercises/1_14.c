#include <stdio.h>

#define START_ASCII_CHARS 32
#define ASCII_CHARS       126

int main()
{
        int c;
        int char_counts[ASCII_CHARS] = { 0 };

        // populate counts
        while ((c = getchar()) != EOF) {
                char_counts[c] += 1;
        }

        // display horizontal histogram
        for (int i = START_ASCII_CHARS; i < ASCII_CHARS; ++i) {
                if (i == ' ') {
                        printf("\\");
                        printf("s");
                } else
                        printf("%c", i);
                for (int j = 0; j < char_counts[i]; ++j) {
                        printf("-");
                }
                printf("\n");
        }
}
