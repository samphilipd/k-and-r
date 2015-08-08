#include <stdio.h>
#define MAX_LINE 1000 // maximum line input size

int getlinelen(char line[], int maxline);
void copy(char to[], char from[]);

// print longest input line
int main()
{
        int len; // current line length
        int max; // maximum line length seen so far
        char line[MAX_LINE]; // current input line
        char longest[MAX_LINE]; // longest line saved here

        max = 0;
        while ((len = getlinelen(line, MAX_LINE)) > 0)
                if (len > max) {
                        max = len;
                        copy(longest, line);
                }
        if (max > 0) { // there was at least one line
                printf("%s\n", longest);
                printf("length: %i\n", max);
        }
        return 0;
}

// getline: read a line into s, return length
int getlinelen(char s[], int lim)
{
        int c, i, t;

        for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i){
                if (i < lim - 1) { // to leave space for the null byte
                        s[i] = c;
                        t = i; // truncate array index to max of limit - 1
                }

        }

        if (c == '\n') {
                s[t] = c;
                ++t;
        }
        s[t] = '\0';
        return i;
}

// copy: copy 'from' into 'to'; assume to is big enough
void copy(char to[], char from[])
{
        int i = 0;

        while ((to[i] = from[i]) != '\0')
                ++i;
}
