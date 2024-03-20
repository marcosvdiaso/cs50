#include <cs50.h>
#include <stdio.h>

void printName();

int main()
{
    printName();
}

void printName(string name)
{
    name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}
