#include <stdio.h>

#define MAX_LEN 1000

int any(char s1[], char s2[]);
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

        printf("Enter characters to search for: ");
        while ((c = getchar()) != '\n' && len1 <= MAX_LEN) {
                s1[len1++] = c;
        }
        s1[len1] = '\0';

        printf("Position of first found character is: %d\n", any(s1, s2));

        return 0;
}

// Returns the first location in string s1 where any character from s2 occurs
// returns -1 if none found
int any(char s1[], char s2[])
{
        int i = 0;
        char c;

        while ((c = s2[i]) != '\0') {
                if (does_contain(s1, c)) {
                        return i;
                }
                ++i;
        }

        return -1;

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
