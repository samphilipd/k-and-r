#include <stdio.h>
#define MAX_LINE 1000 // maximum line input size

int getlinelen(char line[], int maxline);
void reverse(char line[], int length);
void copy(char to[], char from[]);

// remove trailing blanks and tabs from each line of input
// delete entirely blank lines
int main()
{
        int len; // current line length
        char line[MAX_LINE]; // current input line

        while ((len = getlinelen(line, MAX_LINE)) > 0) {
                reverse(line, len);
                printf("%s\n", line);
        }
        return 0;
}

// reverse: reverses the string of length len into s
void reverse(char s[], int len)
{
        char reversed[MAX_LINE]; // temporary holding place for the reversed string
        int i = 0;

        reversed[len] = '\0';
        while ((reversed[len - 1 - i] = s[i]) != '\0')
                ++i;

        copy(s, reversed);
}

// getline: read a line into s, return length. drops newlines
int getlinelen(char s[], int lim)
{
        int c, i;

        for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
                s[i] = c;
        s[i] = '\0';
        return i;
}

// copy: copy 'from' into 'to'; assume to is big enough
void copy(char to[], char from[])
{
        int i = 0;

        while ((to[i] = from[i]) != '\0')
                ++i;
}
