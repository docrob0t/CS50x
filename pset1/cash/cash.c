#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Keep track of the number of coins
    int counter = 0;
    float changeOwed = 0;

     // Prompt user for a positive number
    do
    {
        changeOwed = get_float("Change owed: ");
    }
    while (changeOwed < 0);

    changeOwed *= 100;
    changeOwed = round(changeOwed);

    while (changeOwed >= 25)
    {
        changeOwed -= 25;
        counter++;
    }

    while (changeOwed >= 10)
    {
        changeOwed -= 10;
        counter++;
    }

    while (changeOwed >= 5)
    {
        changeOwed -= 5;
        counter++;
    }

    while (changeOwed >= 1)
    {
        changeOwed -= 1;
        counter++;
    }

    printf("%i", counter);
}