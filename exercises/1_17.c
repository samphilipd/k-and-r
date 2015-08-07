#include <stdio.h>
#define MAX_LINE 1000 // maximum line input size
#define MAX_LINES 10000 // maximum chars to store for all lines
#define LINE_LENGTH 80 //

int getlinelen(char line[], int maxline);
int append(char lines[], char line[], int idx);

// print all input lines longer than 80 characters
// read them into an array of chars with each line as a null-terminated string o
int main()
{
        int len; // current line length
        int idx = 0; // the index after the termination of the previous string
        char line[MAX_LINE]; // current input line
        char lines[MAX_LINES]; // all lines so far

        while ((len = getlinelen(line, MAX_LINE)) != -1) {
                if (len > LINE_LENGTH) {
                        if (idx < MAX_LINES) {
                                idx = append(lines, line, idx);
                        }
                }
        }

        for (int i = 0; i < idx; ++i) {
                char c = lines[i];
                if (c == '\0')
                        printf("\n");
                else
                        printf("%c", c);
        }
        return 0;
}

// getlinelen: read a line into s, return length
int getlinelen(char s[], int lim)
{
        int i;
        char c;

        for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i){
                if (i < lim - 1) { // to leave space for the null byte
                        s[i] = c;
                } else
                        break;

        }
        if (c == EOF)
                return EOF;
        else
                s[i] = '\0';
                return i;
}

// append: write null-terminated string into lines, starting at idx
// returns the new idx
// zeroes line after reading
// does no bounds checking, assumes that the caller made sure that idx is smaller
// than length of line
int append(char lines[], char line[], int idx)
{
        int i = 0;

       while ((lines[i + idx] = line[i]) != '\0')
                ++i;

        lines[i + idx] = '\n';

        ++i;
        return (i + idx);
}
