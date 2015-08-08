#include <stdio.h>

#define MAX_STRING_LENGTH 100

// replace:
//   for(i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
//           s[i] = c;
// with a version that does not use && or ||
int main()
{
        int i = 0,
            lim = MAX_STRING_LENGTH,
            c;
        char s[MAX_STRING_LENGTH];

        while (i < lim - 1) {
                if ((c=getchar()) == '\n') {
                        break;
                } else if (c == EOF) {
                        break;
                } else {
                        s[i++] = c;
                }

        }

        s[i] = '\0';   /* terminate the string */

        return 0;
}
