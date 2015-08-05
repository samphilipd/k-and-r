#include <stdio.h>

#define IN_WORD      1
#define OUT_OF_WORD  0
#define MAX_WORDS    2500
#define NULL_FLAG    0
#define MAX_WORD_LEN 2500

// prints a histogram of word lengths in the input
int main()
{
        int c;
        int lengths[MAX_WORDS] = { NULL_FLAG }; // max number of words to be printed
        int n_word = 0, current_length = 0, state = IN_WORD;

        while ((c = getchar()) != EOF) {
                if (n_word >= MAX_WORDS) {
                        abort();
                }
                if (c == ' ' || c == '\n' || c == '\t') {
                        lengths[n_word] = current_length;
                        current_length = 0;
                        state = OUT_OF_WORD;
                        ++n_word;
                } else {
                        ++current_length;
                        if (state == OUT_OF_WORD) {
                                state = IN_WORD;
                        }
                }
        }

        // find the longest word
        int longest_word_length = 0;
        for (int i = 0; i < MAX_WORDS; ++i) {
                if (longest_word_length >= MAX_WORD_LEN) {
                        abort();
                }
                if (lengths[i] > longest_word_length)
                        longest_word_length = lengths[i];
        }
        printf("longest: %d\n", longest_word_length);

        // prints a horizontal histogram
        // also save frequencies to array
        int length_frequencies[MAX_WORD_LEN + 1] = { 0 };

        for (int i = 1; i <= longest_word_length; ++i) {
                printf("%3d: ", i);
                // int n_words_with_this_length = 0;
                for (int j = 0; j < MAX_WORDS; ++j) {
                        if (lengths[j] == i) {
                                ++length_frequencies[i];
                                printf("-");
                        }
                }
                printf("\n");
        }

        printf("\n===\n\n");

        //prints a vertical histogram

        // work downwards printing a - for each word with length less than or
        // equal to i

        int max_frequency = 0;
        for (int i = 0; i < longest_word_length; ++i) {
                if (length_frequencies[i] > max_frequency)
                        max_frequency = length_frequencies[i];
        }

        for (int i = max_frequency; i >= 0; --i) {
                for (int j = 0; j <= longest_word_length; ++j) {
                        if (i == 0) {
                                printf("%2d", j);
                        } else if (length_frequencies[j] >= i) {
                                printf(" |");
                        } else {
                                printf("  ");
                        }
                }
                putchar('\n');
        }
}
