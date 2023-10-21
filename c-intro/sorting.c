#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

void run(void);
int get_int(void);
int get_random_int(int size);
int in_array(int *arr, size_t size, int value);
void zero_array(int *array, size_t size);
void random_int_array(int *arr, size_t size);
void merge_sort(int *arr, int start, int end);
void merge(int *arr, int start, int end, int mid);
void print_array(int *arr, size_t size);

int main(int argc, char *argv[])
{
    // Variable declaration
    int size;
    int compare;
    double time;

    // Ask user for array size
    size = get_int();

    //Array declaration.
    int i_array[size];

    //Fill array with ZERO
    zero_array(i_array, size);

    //Fill array with random INT`s
    random_int_array(i_array, size);

    compare = strcmp(argv[1], "merge");
    if (compare == 0)
    {
        clock_t start_time = clock();
        merge_sort(i_array, 0, size - 1);
        clock_t end_time = clock();
        time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    }
    printf("It took %f : seconds\n", time);
}

int get_int()
{
    int a;
    printf("Please enter array size: ");
    scanf("%i", &a);
    return a;
}

int get_random_int(int size)
{
    // srand(time(NULL));
    // sleep(1);
    return rand() % size;
}

void zero_array(int *array, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}

void random_int_array(int *arr, size_t size)
{
    int i_count = 0;
    int i_temp;
    while (i_count < size)
    {
        i_temp = get_random_int(size+1);
        if (in_array(arr, size, i_temp) == 0)
        {
            arr[i_count] = i_temp;
            i_count ++;
            // printf("%i inserted to poistion %i \n", i_temp, i_count);
        }
        else
        {
            // printf("The number is already array\n");
        }
    }
}

int in_array(int *arr, size_t size, int value)
{
    for (int i = 0; i < size ; i++)
    {
        if (value == arr[i])
        {
            return 1;
        }
    }
    return 0;
}

void merge_sort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = 0;
    mid = floor((start + end) / 2.0);
    merge_sort(arr, start, mid);
    merge_sort(arr, mid+1, end);
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

void print_array(int *arr, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}