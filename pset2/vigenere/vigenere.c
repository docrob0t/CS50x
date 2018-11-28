#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Make sure the argc is 2,
    // otherwise program should print an error and return 1.
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    // Get the secret key from command-line argument
    string k = argv[1];

    // Check if the key contains any non-alphabetical character
    // Otherwise, convert alphabet to key
    for (int j = 0, n = strlen(k); j < n; j++)
    {
        if (!isalpha(k[j]))
        {
            // Print Error
            printf("Usage: ./vigenere k\n");

            // Exit programme
            return 1;
        }
    }

    // Prompt user for a string for plaintext p
    string p = get_string("plaintext:  ");

    // Print "ciphertext: "
    printf("ciphertext: ");

    // Encrypt message using Vigenère's method
    int spaceCount = 0;

    for (int i = 0, n = strlen(p); i < n; i++)
    {
        // If the character is an alphabet, encrypts alphabet
        if (!isalpha(p[i]))
        {
            printf("%c", p[i]);
            spaceCount++;
        }

        else
        {
            int j = (i - spaceCount) % strlen(k);
            // Preserve case:
            //
            // Check if the letters is capitalized or not
            // If plain text is upper case letters
            if (isupper(p[i]))
            {
                if (isupper(k[j]))
                {
                    p[i] = (p[i] - 65 + k[j] - 65)  % 26 + 65;

                    // Print each character using ASCII values
                    printf("%c", p[i]);
                }
                else
                {
                    p[i] = (p[i] - 65 + k[j] - 97)  % 26 + 65;
                    printf("%c", p[i]);
                }
            }
            // Lower case letters:
            else
            {
                if (isupper(k[j]))
                {
                    p[i] = (p[i] - 97 + k[j] - 65) % 26 + 97;
                    printf("%c", p[i]);
                }
                else
                {
                    p[i] = (p[i] - 97 + k[j] - 97) % 26 + 97;
                    printf("%c", p[i]);
                }
            }
        }
    }

    printf("\n");
    return 0;

}