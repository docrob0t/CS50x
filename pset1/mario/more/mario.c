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
        // print sapces for left pyramid
        for (int j = height - i - 1; j > 0; j--)
        {
            printf(" ");
        }

        // print hashes for left pyramid
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        // print gap
        printf("  ");

        // print hashes for right pyramid
        for (int l = 0; l < i + 1; l++)
        {
            printf("#");
        }

        // print new line
        printf("\n");
    };
}