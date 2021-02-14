#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encipher(string key);

int main (int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];

        int length = strlen(key);

        // Check key length
        if (length == 26)
        {
            // Check for non-alphabetic characters
            for (int i = 0; i < length; i++)
            {
                if (! isalpha(key[i]))
                {
                    printf("Key must only contain alphabetic characters.\n");
                    return 1;
                }

                // Check for repeated characters
                for (int j = i + 1; j < length; j++)
                {
                    if (toupper(key[i]) == toupper(key[j]))
                    {
                        printf("Key must not contain repeated characters.\n");
                        return 1;
                    }
                }
            }

            // Get plaintext and give out ciphertext
            encipher(key);

        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }


    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    return 0;
}

// Encipher function
void encipher(string key)
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int j = 0; j < strlen(plaintext); j++)
    {
        if (isalpha(plaintext[j]))
        {
            for (int i = 0; i < strlen(alphabet); i++)
            {
                if (toupper(plaintext[j]) == toupper(alphabet[i]) && isupper(plaintext[j]))
                {
                    printf("%c", toupper(key[i]));
                }
                else if (toupper(plaintext[j]) == toupper(alphabet[i]) && islower(plaintext[j]))
                {
                    printf("%c", tolower(key[i]));
                }
            }
        }
        else
        {
            printf("%c", plaintext[j]);
        }
    }

    printf("\n");

}
