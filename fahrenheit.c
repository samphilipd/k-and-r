#include <stdio.h>

// print fahrenheit-celsius table

int main()
{
        float fahr;
        int lower, upper, step;

        lower = 0;
        upper = 300;
        step = 20;

        fahr = lower;
        printf("Fahrenheit - Celsius\n");
        while (fahr <= upper) {
                float celsius;
                celsius = (5.0/9.0) * (fahr - 32.0);
                printf("%3.0f\t%6.1f\n", fahr, celsius);
                fahr = fahr + step;
        }
}
