#include <stdio.h>

int main(void){

    const int VALUE = 10;
    int answer;
    printf("Enter the number: ");
    scanf("%i", &answer);

    if (answer > VALUE){
        printf("Your number %i is higher to coded value: %i \n", answer, VALUE);
        if (answer % 2 == 0){
            printf("The number is even the reminder is: %i \n", answer % 2);
            }
        else{
            printf("The number is odd the reminder is: %i \n", answer % 2);
        }
    }
    else if (answer < VALUE){
        printf("Your number %i is lower to coded value: %i \n", answer, VALUE);
        if (answer % 2 == 0){
            printf("The number is even the reminder is: %i \n", answer % 2);
        }
        else{
            printf("The number is odd the reminder is: %i \n", answer % 2);
        }
    }
    else{
        printf("Your number %i is equal to coded value: %i \n", answer, VALUE);
        if (answer % 2 == 0){
            printf("The number is even the reminder is: %i \n", answer % 2);
        }
        else{
            printf("The number is odd the reminder is: %i \n", answer % 2);
        }
    }
    return 0;
}