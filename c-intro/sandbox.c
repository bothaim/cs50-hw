#include <stdio.h>
#include <math.h>

int sort(int *arr, double s, double e);

int main(void)
{
    int i_arr[]= {14, 7, 3, 12, 9, 11, 6, 2};
    int i_size = sizeof(i_arr) / sizeof(i_arr[0]);
    printf("The size of array - %i\n", i_size);
    sort(i_arr, 0, i_size - 1);
}

int sort(int *arr, double s, double e)
{   
    int p = 0;
    if (s < e)
    {
        p = floor((s + e) / 2.0);
        sort(arr, s, p);
        printf("Recursion o")
    }
    if (s >= e)
    {   
        printf("You reached the the state when start - %i, end - %i\n");
        return 0;
    }
}
