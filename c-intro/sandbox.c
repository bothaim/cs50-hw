#include <stdio.h>
#include <math.h>

int sort(int *arr, int start, int end);

int main(void)
{
    int i_arr[]= {3,9,2,0,4,7};
    int i_size = sizeof(i_arr) / sizeof(i_arr[0]);
    printf("The size of array - %i\n", i_size);
    sort(i_arr, 0, i_size);
}

int sort(int *arr, int start, int end)
{   
    //Find right
    printf("Recived size = start - %i, end - %i\n", start, end);
    end -= ceil(end / 2.0);
    if (end == start)
    {
        printf("You reached the size %i array\n", end);
        return end;
    }
    else
    {
        sort(arr, start, end);
    }
    printf("Recursion finished start - %i, end - %i\n", start, end);
}
