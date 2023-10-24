#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

int get_int(void);
int get_random_int(int size);
int in_array(int *arr, size_t size, int value);
void random_int_array(int *arr, size_t size);
void merge_sort(int *arr, int start, int end);
void bubble_sort(int *arr, size_t size);
void insert_sort(int *arr, size_t size);
void merge(int *arr, int start, int end, int mid);
void swap(int *arr, int dest, int src);
void print_array(int *arr, size_t size);
void compare_times(double *arr, size_t size);

int main(void)
{
    // Variable declaration
    int size;
    int compare;
    double time;
    clock_t start_time;
    clock_t end_time;
    size_t times_size = 3;
    double times [times_size];

    // Ask user for array size
    size = get_int();

    // size = 10;

    //Array declaration.
    int array[size];
    int merge_array[size];
    int bubble_array[size];
    int insert_array[size];

    start_time = clock();
    random_int_array(array, size);
    end_time = clock();
    time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time to fill the array is %f\n", time);

    memcpy(merge_array, array, sizeof(array));
    memcpy(bubble_array, array, sizeof(array));
    memcpy(insert_array, array, sizeof(array));

    // printf("Size of array %lu\n", sizeof(array));
    // printf("Size of array value %lu\n", sizeof(array[0]));
    // printf("Length of array %lu\n", sizeof(array)/ sizeof(array[0]));

    for (int i = 0; i < times_size; i++)
    {   
        start_time = clock();
        switch (i)
        {
        case 0: // Merge sort
            merge_sort(merge_array, 0,size-1);
            break;
        
        case 1: // Bubble sort
            bubble_sort(bubble_array, size-1);
            break;
        case 2: // Insert sort
            insert_sort(insert_array, size);
            break;
        }
        end_time = clock();
        time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("The case %i, sort time is - %f\n", i,time);
        times[i] = time;
    }

    compare_times(times, times_size);

    // print_array(merge_array, size);
    // print_array(bubble_array, size);
    // print_array(insert_array, size);
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

void bubble_sort(int *arr, size_t size)
{
    // Set swap counter to ZERO
    int i_swap_counter;
    int i_buble_size;

    i_buble_size = size;

    do
    {
        i_swap_counter = 0;
        for (int i = 0; i < i_buble_size; i++)
        {
            if (arr[i] > arr[i+1])
            {
                swap(arr, i, i+1);
                i_swap_counter +=1;
            }
        }
        i_buble_size -= 1;
    } while (i_swap_counter != 0);
}

void insert_sort(int *arr, size_t size)
{
    int min;
    int pos = 0;
    int src = 0;
    do
    {   
        min = arr[pos];
        for (int i = pos; i < size; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
                src = i;
            } 
        }
        swap(arr, pos, src);
        pos += 1;
        src = pos;
    } while (pos < size);
    
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

void swap(int *arr, int dest, int src)
{
    int temp = arr[dest];
    arr[dest] = arr[src];
    arr[src] = temp;
}

int get_int()
{
    int a;
    printf("Please enter array size: ");
    scanf("%i", &a);
    return a;
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

int get_random_int(int size)
{
    // srand(time(NULL));
    // sleep(1);
    return rand() % size;
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

void print_array(int *arr, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

void compare_times(double *arr, size_t size)
{
    double temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            temp = arr[j] / arr[i];
            if (temp != 1)
            {
                printf("The time[%i] to time[%i] %f\n", i, j,temp);
            }
        } 
    }
}