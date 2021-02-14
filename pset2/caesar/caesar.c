#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (! isdigit(argv[1][i]))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }

        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        string plaintext = get_string("plaintext: ");

        int textLength = strlen(plaintext);

        int key = atoi(argv[1]);

        printf("ciphertext: ");

        for (int i = 0; i < textLength; i++)
        {
            if (isalpha(plaintext[i]))
            {
                for (int j = 0; j < 26; j++)
                {
                    if(toupper(plaintext[i]) == alphabet[j] && isupper(plaintext[i]))
                    {
                        int n = j + key;

                        while (n > 25)
                        {
                            n = n % 26;
                        }
                        printf("%c", alphabet[n]);
                    }
                    else if (toupper(plaintext[i]) == alphabet[j] && islower(plaintext[i]))
                    {
                        int n = j + key;

                        while (n > 25)
                        {
                            n = n % 26;
                        }
                        printf("%c", tolower(alphabet[n]));
                    }
                }
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    printf("\n");
    return 0;
}
