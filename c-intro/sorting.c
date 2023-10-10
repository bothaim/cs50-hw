#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

void run(void);
int get_int(void);
int get_random_int(int size);
int in_array(int *arr, size_t size, int value);
void zero_array(int *array, size_t size);
void sort(int *arr, int size);
int sort_left(int *arr, int start, int end);

int main(void)
{
    run();
}

void run(void)
{
    // Variable declaration
    int size;
    int i_temp;
    int i_count = 0;

    // Ask user for array size
    size = get_int();

    //Dynamic array declaration.
    int i_array[size];
    zero_array(i_array, size);
    while (i_count < size)
    {
        i_temp = get_random_int(size+1);
        if (in_array(i_array, size, i_temp) == 0)
        {
            i_array[i_count] = i_temp;
            i_count ++;
            // printf("%i inserted to poistion %i \n", i_temp, i_count);
        }
        else
        {
            // printf("The number is already array\n");
        }
    }
    for (int i = 0; i < size; i++)
    {
        // printf("Array[%i] - %i \n", i, i_array[i]);
    }
    sort(i_array, size);
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

void sort(int *arr, int size)
{
    sort_left(arr, 0, size - ceil(size/2));
}

int sort_left(int *arr, int start, int end)
{
    double i_temp;
    if (start == end)
    {
        return 0;
    }
    else
    {   
        i_temp = end / 2.0;
        end -= ceil(i_temp);
        sort_left(arr, start, end);
    }
    printf("START{%i} - END{%i}\n", start, end);
}