#include <cs50.h>
#include <stdio.h>

int main()
{
    int n;     /* This variable is to represent the height */
    int c = 1; /* This is a counter used in the for loop to track the number of '#' to print */

    do
    {
        n = get_int("Height: "); /* Prompt the user to input the height */
    }
    while (n < 1 || n > 8); /* if n lower than 1 or higher than 8 it repeats the question */

    int d = n - 1; /* Initializes the variable 'd' to 'n - 1', 'd' represents the number of spaces
                      to print before each '#' in the pyramid, We subtract one to avoid having an
                      extra space in the last row */

    for (int i = 0; i < n; i++) /* Loop for height */
    {
        for (int k = d; k > 0; k--)
        {
            /* Loop for spaces before the '#' in each row except the last one */
            printf(" ");
        }

        for (int j = 0; j < c; j++)
        {
            /* Loop for printing '#' in each row */
            printf("#");
        }

        printf("\n"); /* Prints next line after each row */
        c++;          /* Increment 'c' to print more '#' in the next row */
        d--;          /* Decrement 'd' to adjust the number of spaces for the next row */
    }
}
