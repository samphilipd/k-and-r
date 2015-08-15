#include <stdio.h>

int binsearch_oneloop(int x, int v[], int n);
int binsearch(int x, int v[], int n);

int main()
{
}

// binsearch_oneloop: the same as below with only one conditional inside the loop
int binsearch_oneloop(int x, int v[], int n)
{
        int low, mid, high;

        low = 0;
        high = n - 1;
        while (low <= high) {
                mid = low + high / 2;
                if (x < v[mid])
                        high = mid - 1;
                else if (x > v[mid])
                        low = mid + 1;
                else // found match
                        return mid;
        }
        return -1; // no match
}


// binsearch: find x in ordered array v of length n
int binsearch(int x, int v[], int n)
{
        int low, mid, high;

        low = 0;
        high = n - 1;
        while (low <= high) {
                mid = low + high / 2;
                if (x < v[mid])
                        high = mid - 1;
                else if (x > v[mid])
                        low = mid + 1;
                else // found match
                        return mid;
        }
        return -1; // no match
}
