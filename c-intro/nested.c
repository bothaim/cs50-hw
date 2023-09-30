#include <stdio.h>
#include <ctype.h>

void nested(void);
int set_option(void);
void square(void);
void triangle(void);
//void reverse_triangle(void);
char quit_handler(void);
int get_length(char name);


int main(void)
{

    //execute module
    nested();
}

void nested(void)
{

    //Variable declaration
    int option;
    char ch;

    //Run the program until user close it
    do
    {
        
        //Set option
        option = set_option();
        if (option == 1)
        {
            square();
        }
        else if (option == 2)
        {
            triangle();
        }
        else if (option == 3)
        {
            //reverse_triangle();
        }
        else
        {
            printf("Nothing was selected\n");
        }
        ch = quit_handler();
    } while (ch != 'y');
    
}

int set_option(void)
{

    //Variable declarartion
    int option;
    //Option promt
    printf("Square matrix: 1\n");
    printf("Traiangle matrix: 2\n");
    printf("Reverse traingle matrix: 3\n");
    printf("Select option: ");
    scanf("%i", &option);
    return option;
}

void square(void)
{
    //Declare variable
    int x;
    int y;
    
    //Get X
    x = get_length('x');

    //Get Y
    y = get_length('y');

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    

}

void triangle(void)
{
    //Declare variable
    int x;
    int y;
    int n;

    //Get X
    x = get_length('x');

    //Get Y
    y = get_length('y');

    n = x - 1;

    for (int i = 0; i < y; i++)
    {
        for (int j = n; j < x; j++)
        {
            printf("*"); 
        }
        n --;
        printf("\n");
    }
    

}

int get_length(char name)
{
    int x;
    printf("Define %c length of matrix: ", name);
    scanf("%i", &x);
    return x;
}



char quit_handler(void)
{
    //Variable declaration
    char ch;

    //Quit promt
    printf("Would you like to quit [y/n]? :");
    scanf(" %c", &ch);
    return tolower(ch);
}