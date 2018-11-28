#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int height = 0;
    // Prompt user for a positive number
    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);

    //
    for (int i = 0; i < height; i++)
    {
        // Print how many space each row
        for (int j = height - i - 1; j > 0; j--)
        {
            printf(" ");
        }

        // Print how many hashes each row
        for (int k = 0; k < i + 2; k++)
        {
            printf("#");
        }

        printf("\n");
    };
}