#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Make sure the argc is 2,
    // otherwise program should print an error and return 1.
    if (argc == 2)
    {
        // Get the secret key from command-line argument
        //     string k = argv[1];
        //
        // Turn key into integer, convert that string to an actual int
        //     int key = atoi(k);

        int k = atoi(argv[1]);

        // Prompt for plaintext
        string p = get_string("plaintext:  ");

        // Print "ciphertext: "
        printf("ciphertext: ");

        // Encrypt message using Caesar's method
        for (int i = 0, n = strlen(p); i < n; i++)
        {
            // If the character is an alphabet, encrypts alphabet
            if (isalpha(p[i]))
            {
                // Preserve case:
                //
                // Check if the letters is capitalized or not
                // Upper case letters:
                if (isupper(p[i]))
                {
                    // Start with ASCII values                      (p[i])
                    // Convert from ASCII value    A = 65
                    // to alphabetical index where A = 0            (-65)
                    // Add the secret key                           (k)
                    // Wrap around from Z to A (index 26 back to 1) (%26)
                    // Convert back to ASCII values                 (+65)

                    p[i] = (p[i] - 65 + k) % 26 + 65;

                    // Print each character using ASCII values
                    printf("%c", p[i]);

                }
                // Lower case letters:
                else
                {
                    p[i] = (p[i] - 97 + k) % 26 + 97;
                    printf("%c", p[i]);
                }
            }

            // If the character is NOT an alphabet, just print the character
            else
            {
                printf("%c", p[i]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("There should be 1 command-line argument only\n");
        return 1;
    }
}