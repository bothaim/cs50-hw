#include <stdio.h>
#include <string.h>

int get_int(char *promt);
long get_factorial(int value);
void factorial(void);

int main(int argc, char *argv[])
{   
    int compare;
    if (argc > 1)
    {
        compare = strcmp(argv[1], "factorial");
        if (compare == 0)
        {
            factorial();
        }
    }
    else
    {
        printf("No parameters been provided - exit\n");
    }
}

void factorial(void)
{
    // Variable declaraion
    int value;
    long result;

    value = get_int("Please enter the number");
    long results[value];
    int times;
    printf("You recived - %i\n", value);
    for (int i = 1; i <= value; i++)
    {
        results[i-1] = get_factorial(i);
        // printf("Factorial of %i\t= %li\n", i, result);
    }

    for (int i = 0; i < value; i++)
    {   
        if (i == 0)
        {
            printf("Factorial of %i\t= %li\t| Intial factorial\n", i+1, results[i]);
        }
        else
        {   
            times = results[i] / results[i-1];
            printf("Factorial of %i\t= %li\t| times\t %i\n", i+1, results[i], times);
        }
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
    if (value == 1)
    {
        return value;
    }
    return value * get_factorial(value - 1);
}
