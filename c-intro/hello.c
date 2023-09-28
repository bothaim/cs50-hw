#include <stdio.h>

int main(void){

    char get_answer[100];
    printf("Enter your name: ");
    scanf("%s", get_answer);
    printf("Hello, %s. \n", get_answer);
    return 0;
}