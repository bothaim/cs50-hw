#include <stdio.h>
#include <math.h>

void sort(int *arr, int start, int end);
void merge(int *arr, int start, int end, int mid);

int main(void)
{
    int i_arr[]= {14, 7, 3, 12, 9, 11, 6, 2, 0, 5, 30, 1, 4};
    int i_size = sizeof(i_arr) / sizeof(i_arr[0]);
    printf("The size of array - %i\n", i_size);
    printf("Before sort: ");
    for (int i = 0; i < i_size; i++)
    {
        printf("%i ", i_arr[i]);
    }
    printf("\n");
    
    sort(i_arr, 0, i_size - 1);
    for (int i = 0; i < i_size; i++)
    {
        printf("%i ", i_arr[i]);
    }
    printf("\n");
    
}

void sort(int *arr, int start, int end)
{   
    if (start >= end)
    {
        // printf("Base state reached start = %i, end=%i\n", start, end);
        return;
    }
    int mid = 0;
    mid = floor((start + end)/ 2.0);
    sort(arr, start, mid);
    sort(arr, mid+1, end);
    merge(arr, start, end, mid);
}

void merge(int *arr, int start, int end, int mid)
{   
    int temp_size = (end - start) + 1;
    int temp_a [temp_size];
    int pos = 0;
    int int_start = start;
    int int_mid = mid + 1;
    while (int_start <= mid || int_mid <= end)
    {
        if (int_start > mid)
        {
            temp_a[pos] = arr[int_mid];
            int_mid++;
            pos++;
        }
        else if (int_mid > end)
        {
            temp_a[pos] = arr[int_start];
            int_start++;
            pos++;           
        }
        else
        {
            if (arr[int_start] < arr[int_mid])
            {
                temp_a[pos] = arr[int_start];
                int_start++;
                pos++;
            }
            else if (arr[int_start] > arr[int_mid])
            {
                temp_a[pos] = arr[int_mid];
                int_mid++;
                pos++;
            }       
        }        
    }

    int i = start;
    int j = 0;
    for (; i < end + 1; i++, j++)
    {
        arr[i] = temp_a[j];
    }
    
}