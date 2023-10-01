#include <stdio.h>

int main(void){

    int a;
    a = 100;
    int *pt = &a;
    printf("Address of a = %p\n", &a);
    printf("Address of pointer a = %p\n", pt);
    printf("The value of a = %i\n", a);
    printf("Value of pointer a = %i\n", *pt);
    *pt = 200;
    printf("The value of a = %i\n", a);
    printf("Value of pointer a = %i\n", *pt);
    a = 300;
    printf("The value of a = %i\n", a);
    printf("Value of pointer a = %i\n", *pt);

}