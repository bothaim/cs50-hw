#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void my_array(void);
int my_random_int(void);
int my_array_size(long full_array, long array_clust);

int main(void)
{
    my_array();

}

void my_array(void)
{
    int i_array_size = my_random_int();
    int a_temp [i_array_size];
    int i_length = my_array_size(sizeof(a_temp), sizeof(a_temp[0]));
    int i_temp;
    printf("The size of array - %li, the lize of cluster - %li, the aray length - %i\n", sizeof(a_temp), sizeof(a_temp[0]), i_length);
    for (int i = 0; i < i_length; i++)
    {
        i_temp = my_random_int();
        a_temp[i] = i_temp;
    }
    for (int j = 0; j < i_length; j++)
    {
        printf("a_temp[%i] - %i\n", j, a_temp[j]);
    }
    
}

int my_random_int(void)
{
    // srand(time(NULL));
    return rand() % 100;
}

int my_array_size(long full_array, long array_clust)
{
    return full_array / array_clust;
}