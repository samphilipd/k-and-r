#include <stdio.h>
#define MAX_LINE 1000 // maximum line input size

int getlinelen(char line[], int maxline);
void strip_whitespace(char line[], int length);
void copy(char to[], char from[]);

// remove trailing blanks and tabs from each line of input
// delete entirely blank lines
int main()
{
        int len; // current line length
        char line[MAX_LINE]; // current input line

        while ((len = getlinelen(line, MAX_LINE)) > 0) {
                strip_whitespace(line, len);
                printf("%s\n", line);
        }
        return 0;
}

// strip_whitespace: strips trailing whitespace from array of chars
// returns an empty string if it is all whitespace
void strip_whitespace(char s[], int len)
{
        int c;
        int i;

        for (i = len - 1; i >= 0; --i) { // start at len - 1 so we ignore null byte
                c = s[i];
                if (!(c == ' ' || c == '\t' || c == '\n' || c == '\r')) {
                        ++i; // so we write the null byte just AFTER this char
                        break;
                }
        }
        s[i] = '\0'; // terminate the string
}

// getline: read a line into s, return length
int getlinelen(char s[], int lim)
{
        int c, i;

        for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
                s[i] = c;
        if (c == '\n') {
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}
