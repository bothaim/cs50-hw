#include <stdio.h>

int main(void)
{
    int i_arry [20];
    printf("Size of array - %li, size of array cluster %li \n", sizeof(i_arry), sizeof(i_arry[0]));

}