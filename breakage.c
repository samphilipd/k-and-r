#include <stdio.h>

// count digits, whitespace and others
int main()
{
        int second[10];
        int arr[10];


        for (int i = 0; i < 10; ++i) {
                arr[i] = 10;
                second[i] = 20;
        }

        arr[15] = 30;

        for (int i = 0; i < 20; ++i)
                printf("%d\n", arr[i]);
}
