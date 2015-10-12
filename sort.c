#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char * lineptr[MAXLINES]; // pointers to text lines

int readlines(char * lineptr[], int nlines);
void writelines(char * lineptr[], int nlines);

void mysort(char *lineptr[], int left, int right);

// sort input lines
int main()
{
        int nlines; // number of input lines read

        if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
                mysort(lineptr, 0, nlines - 1);
                writelines(lineptr, nlines);
                return 0;
        } else {
                printf("error: input is too big to sort\n");
                return 1;
        }
}

#define MAXLEN 1000 // max length of any input line
int getlinelen(char *, int);
char *alloc(int);

// readlines: read input lines
int readlines(char *lineptr[], int maxlines)
{
        int len, nlines;
        char *p, line[MAXLEN];

        nlines = 0;
        while ((len = getlinelen(line, MAXLEN)) > 0)
                if (nlines >= maxlines || (p = alloca(len)) == NULL)
                        return -1;
                else {
                        line[len - 1] = '\0'; // delete newline
                        strcpy(p, line);
                        lineptr[nlines++] = p;
                }
        return nlines;
}

// writelines: write output lines
void writelines(char * lineptr[], int nlines)
{
        while (nlines-- > 0)
                printf("%s\n", *lineptr++);
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

// mysort: sort v[left]...v[right] into increasing order
void mysort(char * v[], int left, int right)
{
        int i, last;
        void swap(char *v[], int i, int j);

        if (left >= right) // do nothing if array contains fewer than two elements
                return;
        swap(v, left, (left + right) / 2);
        last = left;
        for (i = left + 1; i <= right; ++i)
                if (strcmp(v[i], v[left]) < 0)
                        swap(v, ++last, i);
        swap(v, left, last);
        mysort(v, left, last - 1);
        mysort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
        char *temp;

        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
}
