#include <stdio.h>

float fahr_to_celsius(int fahr);

// print fahrenheit-celsius table using conversion function
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
                printf("%3.0f\t%6.1f\n", fahr, fahr_to_celsius(fahr));
                fahr = fahr + step;
        }
}

float fahr_to_celsius(int fahr)
{
        return (5.0/9.0) * (fahr - 32.0);
}
