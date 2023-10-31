#include <stdio.h>

int get_int(char *promt);
int get_factorial(int value);

int main(void)
{   
    // Variable declaraion
    int value;
    int result;

    value = get_int("Please enter the number");
    printf("You recived - %i\n", value);
    result = get_factorial(value);
    printf("Result = %i\n", result);
}

int get_int(char *promt)
{   
    int value;
    printf("%s :", promt);
    scanf("%i", &value);
    return value;
}

int get_factorial(int value)
{
    int factorial;
    int result;
    if (value == 1)
    {
        return value;
    }
    factorial = get_factorial(value - 1);
    result = value * factorial;
    return result;
}
