#include <stdio.h>
#define MAXLINE 1000

unsigned getlinelen(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould"; // pattern to search for

// find all lines matching pattern
int main()
{
        char line[MAXLINE];
        int found = 0;

        while (getlinelen(line, MAXLINE) > 0) {
                int pos;
                if ((pos = strrindex(line, pattern)) >= 0) {
                        printf("%s(match found at: %d)\n", line, pos);
                        ++found;
                }
        }

        return found;
}

// getlinelen: get line into s, return length
unsigned getlinelen(char s[], int lim)
{
        int c, i;

        i = 0;
        while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
                s[i++] =c;
        if (c == '\n')
                s[i++] = c;
        s[i] = '\0';
        return i;
}

// strindex: return index of rightmost occurence of t in s, -1 if not found
int strrindex(char s[], char t[])
{
        int i, j, k;
        int pos = -1;

        for (i = 0; s[i] != '\0'; ++i) {
                for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k)
                        ;
                if (k > 0 && t[k] == '\0')
                        pos = i;
        }
        return pos;
}
