#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
        unsigned x = 0xFF;
        printf("value before setbits: %d\n", x);

        printf("value after setbits: %d\n", setbits(x, 4, 3, 0x00));
}

// returns x with the n bits that begin at position p set to the rightmost n
// bits of y, leaving the other bits unchanged
// e.g. setbits(0xFF, 4, 3, 0x00) => 0xF1 or 241
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
        y = y & ~(~0 << n); // null all the bits from a pos higher than n
        y = y << (p - n); // move bits into position for masking
        x = x & (~0 << n); // null the last n bits
        return (x | y);
}
