#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];
    char number[50];
}
person;


int main(void)
{
    
    char b[20] = "Hello";
    //Persons
    person people[2];
    strcpy(people[0].name, "John");
    strcpy(people[0].number, "23");
    strcpy(people[1].name, "Mick");
    strcpy(people[1].number, "19");

    for (int i = 0; i < 2; i++)
    {
        printf("%s - %s\n", people[i].name, people[i].number);
    }
    return 0;
}