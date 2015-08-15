#include <stdio.h>
#include <limits.h>
#include <float.h>

void print_integral_ranges_from_constants(void);
void print_char_ranges_programmatically(void);
void print_integer_ranges_programatically(void);

// ranges: determines ranges of char, short, int and long (unsigned and signed)
// both from constants and programmatically
int main()
{
        printf("Bits in a char: %d\n\n", CHAR_BIT);
        print_integral_ranges_from_constants();
        print_char_ranges_programmatically();
        print_integer_ranges_programatically();
}

void print_integral_ranges_from_constants()
{
        printf("Integral Ranges (from constants)\n");

        printf("char max: %d\n", SCHAR_MAX);
        printf("char min: %d\n", SCHAR_MIN);
        printf("unsigned char max: %u\n", UCHAR_MAX);
        putchar('\n');
        printf("short max: %d\n", SHRT_MAX);
        printf("short min: %d\n", SHRT_MIN);
        printf("unsigned short max: %u\n", USHRT_MAX);
        putchar('\n');
        printf("int max: %d\n", INT_MAX);
        printf("int min: %d\n", INT_MIN);
        printf("unsigned int max: %u\n", UINT_MAX);
        putchar('\n');
        printf("long max: %ld\n", LONG_MAX);
        printf("long min: %ld\n", LONG_MIN);
        printf("unsigned long max: %lu\n", ULONG_MAX);
        putchar('\n');
}

void print_char_ranges_programmatically()
{
        printf("Char ranges (determined programmatically)\n");

        int char_range = 1 << CHAR_BIT;

        printf("char max: %d\n", char_range / 2 - 1);
        printf("char min: %d\n", 0 - char_range / 2);
        printf("unsigned char max: %d\n", char_range - 1);
}

void print_integer_ranges_programatically()
{
        printf("Int ranges (determined programmatically)\n");

        int step_size = 256;

        int i_max = 0;
        while ((i_max + step_size) > i_max) { // WARNING: signed overflow is undefined
                i_max += step_size;
        }
        while ((i_max + 1) > i_max) {
            ++i_max;
        }
        printf("int max: %d\n", i_max);

        int i_min = 0;
        while ((i_min - step_size) < i_min) { // WARNING: signed overflow is undefined
                i_min -= step_size;
        }
        while ((i_min - 1) < i_max) {
            --i_max;
        }
        printf("int min: %d\n", i_min);

        unsigned int ui_max = 0;
        while ((ui_max + step_size) > ui_max) {
                ui_max += step_size;
        }
        while ((ui_max + 1) > ui_max) {
                ++ui_max;
        }
        printf("unsigned int max: %u\n", ui_max);

}
