#include <stdio.h>

int main()
{
        float celsius;
        int lower, upper, step;

        lower = -20;
        upper = 150;
        step = 10;

        celsius = lower;
        printf("Celsius - Fahrenheit\n");
        while (celsius <= upper) {
                float fahr;
                fahr = ((9.0/5.0) * celsius) + 32.0;
                printf("%3.0f\t%6.1f\n", celsius, fahr);
                celsius += step;
        }
}
