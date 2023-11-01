#include <stdio.h>

int get_int(char *promt);
long get_factorial(int value);

int main(void)
{   
    // Variable declaraion
    int value;
    long result;

    value = get_int("Please enter the number");
    printf("You recived - %i\n", value);
    for (int i = 1; i <= value; i++)
    {
        result = get_factorial(i);
        printf("Factorial of %i\t= %li\n", i, result);
    }
}

int get_int(char *promt)
{   
    int value;
    printf("%s :", promt);
    scanf("%i", &value);
    return value;
}

long get_factorial(int value)
{
    long factorial;
    long result;
    if (value == 1)
    {
        return value;
    }
    factorial = get_factorial(value - 1);
    result = value * factorial;
    return result;
}