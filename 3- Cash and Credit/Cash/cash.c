#include <cs50.h>
#include <stdio.h>

int main()
{
    int change;
    int q = 0; // 25c variable
    int d = 0; // 10c variable
    int n = 0; // 5c variable
    int p = 0; // 1c variable
    int total;

    do // Prompt the user for a input of change owed, if lower than 0 than it asks again
    {
        change = get_int("Change owed:");
    }
    while (change < 0);

    while (change > 0)
    /* This loop iterates while there is still change owed.
   It checks the value of the change owed and subtracts the
   value of the largest possible coin denomination,
   incrementing the corresponding coin counter.
   This process repeats for all types of coin denominations. */
    {
        if (change >= 25)
        {
            change = change - 25;
            q++;
        }
        else if (change >= 10 && change < 25)
        {
            change = change - 10;
            d++;
        }
        else if (change >= 5 && change < 10)
        {
            change = change - 5;
            n++;
        }
        else if (change >= 1 && change < 5)
        {
            change = change - 1;
            p++;
        }
    }

    total = q + d + n + p; /* In the total variable it's stored all the coin's counters togheter,
                            calculating the total of coins */
    printf("%i\n", total); // Prints the total of needed coins
}
