#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 4.3;
    int a = ceil(x);
    int b = floor(x);
    printf("Original - %f, ceil - %i, floor - %i\n", x, a, b);
}