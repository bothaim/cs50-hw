#include <stdio.h>
#include <math.h>

int sort(int *arr, int start, int end);

int main(void)
{
    int i_arr[]= {14, 7, 3, 12, 9, 11, 6, 2};
    int i_size = sizeof(i_arr) / sizeof(i_arr[0]);
    printf("The size of array - %i\n", i_size);
    sort(i_arr, 0, i_size - 1);
}

int sort(int *arr, int start, int end)
{   
    if (start >= end)
    {
        printf("Base state reached start = %i, end=%i\n");
        return 0;
    }
    int mid = 0;
    mid = floor((start + end)/ 2.0);
    printf("Divide starting at positions start = %i, end = %i, mid = %i\n", start, end, mid);
    sort(arr, start, mid);
    sort(arr, mid+1, end);
    printf("Division Completed.\n");
    printf("Merge can be started in range %i - %i, with mid = %i\n", start, end, mid);
}
