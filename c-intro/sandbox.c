#include <stdio.h>
#include <math.h>

int f_sort_left(int start, int end);

int main(void)
{
    int i_arr[]= {3,9,2,0,4,7};
    int i_size = sizeof(i_arr) / sizeof(i_arr[0]);
    printf("The size of array - %i\n", i_size);

    int end = i_size - ceil(i_size / 2.0);
    printf("Right half of the array = start - 0, end - %i\n", end);
    f_sort_left(0, end);
}

int f_sort_left(int start, int end)
{
    if (end == start)
    {
        return 0;
    }
    else
    {
        end -= ceil(end / 2.0);
        printf("Now end - %i\n", end);
        f_sort_left(start, end);
        return 1;
    }
    printf("Is this printed\n");
}
