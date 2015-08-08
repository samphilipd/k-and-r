#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMITER      ' '
#define LINE_WIDTH      80
#define MAX_WORD_LENGTH 100
#define SPACE_WIDTH     1

int scan(char word[]);
int buffer(char word[]);


// Write a program to 'fold' long input lines into two or more shorter lines
// after the last non-blank character that occurs before the n-th column of
// input. Make sure your program does something intelligent with very long
// lines, and if there are no blanks or tabs before the specified column.

int main()
{
    int remaining = LINE_WIDTH;
    char word[MAX_WORD_LENGTH] = { '\0' };
    
    while((scan(word) > EOF)) {
        int width = strlen(word);
        
        if (word[width + 1] == '\n') {
            remaining = LINE_WIDTH;
        } else if (width > remaining) {
            printf("\n");
            remaining = LINE_WIDTH - width;
        } else {
            remaining = remaining - width - SPACE_WIDTH;
        }
        
        printf("%s", word);
        putchar(' ');
    }
    
    return EXIT_SUCCESS;
}

// scanning state. waiting for beginning of word
int scan(char word[])
{
    char c;
    
    while ((c = getchar()) != EOF) {
        if (c != DELIMITER) {
            word[0] = c;
            return buffer(word);
        }
    }
    
    return EOF;
}

// buffering state. waiting for end of word
int buffer(char word[])
{
    int c, idx = 1;
    
    while ((c = getchar())) {
        if (c != DELIMITER && c != EOF && c != '\n' && idx < MAX_WORD_LENGTH) {
            word[idx] = c;
        } else {
            if (c == '\n') {
                word[idx] = '\n';
                word[idx + 1] = '\0';
            } else {
                word[idx] = '\0';
            }
            return strlen(word);
        }
        
        ++idx;
    }
    
    return EOF;
}
