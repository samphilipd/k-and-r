#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getlinelen(void);
void copy(void);

// print longest input line: using externs - DON'T EVER DO THIS
int main()
{
        int len;
        extern int max;
        extern char longest[];

        max = 0;
        while ((len = getlinelen()) > 0)
                if (len > max) {
                        max = len;
                        copy(); // fucking what? unreadable bullshit, never use externs
                }
        if (max > 0)
                printf("%s", longest);
        return 0;
}

// getlinelen: using externs
int getlinelen(void)
{
        int c, i;
        extern char line[];

        for (i = 0;
                i < MAXLINE - 1 &&
                (c = getchar()) != EOF &&
                c != '\n';
                ++i)
        if (c == '\n') {
                line[i] = c;
                ++i;
        }
        line[i] = '\0';
        return i;
}

// copy: using externs
void copy(void)
{
        int i;
        extern char line[], longest[];

        i = 0;
        while ((longest[i] = line[i]) != '\0')
                ++i;
}
