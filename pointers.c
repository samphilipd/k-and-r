#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// strcpy in pointer form
// copies t into s
void mystrcpy(char *s, char *t)
{
        while ((*s++ = *t++)) // null byte evaluates to false, exiting loop
                ;
}

// strcmp (compare string) in pointer form
// return < 0 if s < t, 0 if s == t, > 0 if s > t
int mystrcmp(char *s, char *t)
{
        for ( ; *s == *t; ++s, ++t)
                if (*s == '\0')
                        return 0;
        return *s - *t;
}

// strcat: copies the string t to the end of s
// assumes s is big enough
void mystrcat(char *s, char *t)
{
        while (*++s != '\0')
                ;
        mystrcpy(s, t);
}

// strend: returns 1 if string t occurs at the end of string s, otherwise 0
int mystrend(char *s, char *t)
{
        char *start_t = t;

        // move to end of each string
        while (*++s)
                ;
        while (*++t)
                ;
        // compare from end to beginning
        while (t > start_t)
                if (*--t != *--s)
                        return 0;
        return 1;
}

// mystrncopy: copy at most n characters of string ct to s; return s
char * mystrncpy(char *s, const char *ct, size_t n)
{
        char *p;

        p = s;

        for (int i = 0; i < n; ++i) {
                if (*ct) {
                        *p++ = *ct++;
                } else {
                        // reached the end of ct, copy zeroes
                        *p++ = '\0';
                }
        }

        return s;
}

// mystrncat: concatenate at most n characters of string ct to end of string s,
// terminate s with NUL; return s
char * mystrncat(char *s, const char *ct, size_t n)
{
        char *p;
        p = s;

        // advance to end of *s
        while (*++p != '\0')
                ;

        for (int i = 0; i < n; ++i) {
                *p++ = *ct++;
        }

        *p = '\0';

        return s;
}

// mystrncmp: compare at most n characters of string cs to string ct;
// return < 0 if cs < ct, 0 if cs == ct or >0 if cs > ct
int mystrncmp(const char *cs, const char *ct, size_t n)
{
        for (int m = 0; *cs == *ct; ++cs, ++ct)
                if (*cs == '\0' || ++m == n)
                        return 0;
        return *cs - *ct;
}


int main()
{
        char t[100] = "hello, Sam";
        char s[20];
        char u[] = "hello, Steve";

        mystrcpy(s, t);
        printf("%s\n", s);

        printf("compared: %d\n", mystrcmp(s, u));

        mystrcat(t, ". How are you?");
        printf("%s\n", t);

        printf("should be 1: %d\n", mystrend(u, "eve"));
        printf("should be 0: %d\n", mystrend(u, "neve"));

        char *copy_to = (char*) malloc(10*sizeof(char));
        memset(copy_to, '\0', 10);
        copy_to = mystrncpy(copy_to, t, 5);

        printf("should be 'hello': %s\n", copy_to);

        char v[20] = "hello, ";
        char w[20] = "Sam.";
        printf("should be 'hello, Sam.': %s\n", mystrncat(v, w, 4));

        char x[20] = "hello";
        char y[20] = "hellp";
        printf("should be 0: %d\n", mystrncmp(x, y, 4));
        printf("should be -1: %d\n", mystrncmp(x, y, 5));
}
