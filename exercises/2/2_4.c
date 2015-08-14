#include <stdio.h>

#define MAX_LEN 1000

void squeeze(char remove_chars[], char to_squeeze[], int len);
int does_contain(char s[], char c);

int main()
{
        char c;
        char s1[MAX_LEN + 1];
        char s2[MAX_LEN + 1];
        int len1 = 0;
        int len2 = 0;

        printf("Enter string: ");
        while ((c = getchar()) != '\n' && len2 <= MAX_LEN) {
                s2[len2++] = c;
        }
        s2[len2] = '\0';

        printf("Enter characters to remove: ");
        while ((c = getchar()) != '\n' && len1 <= MAX_LEN) {
                s1[len1++] = c;
        }
        s1[len1] = '\0';

        squeeze(s1, s2, len2);

        printf("Squeezed string is: %s\n", s2);

        return 0;
}

// removes every character in remove_chars from to_squeeze
void squeeze(char remove_chars[], char to_squeeze[], int len)
{
        char c;
        int i = 0;
        int j = 0;

        while (to_squeeze[i] != '\0') {
                c = to_squeeze[i++];
                if (does_contain(remove_chars, c)) {
                        continue;// ignore character and move on to next one
                } else {
                        to_squeeze[j++] = c; // push character onto tmp
                }
        }

        to_squeeze[j] = '\0';
}

// returns 1 if s contains c, otherwise 0
int does_contain(char s[], char c) {
        int i = 0;

        while (s[i] != '\0') {
                if (s[i++] == c)
                        return 1;
        }

        return 0;
}
