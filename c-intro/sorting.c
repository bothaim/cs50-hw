#include <stdio.h>

void sort(void);
int get_int(void);

int main(void)
{
    sort();
}

void sort(void)
{
    // Variable declaration
    int size;

    // Ask user for array size
    size = get_int();

    //Array decalration
    int i_array[size];
    printf("%li", sizeof(i_array) / sizeof(i_array[0]))
}

int get_int(){
    int a;
    printf("Please enter array size: ");
    scanf("%i", &a);
    return a;
}