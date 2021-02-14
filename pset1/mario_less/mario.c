#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    printf("Stored: %i\n", height);

    for (int rows = 0; rows < height; rows++)
    {
        int spaces = (height - 1) - rows;
        int hashtags = rows + 1;

        for (int i = 0; i < spaces; i++)
        {
            printf(" ");
        }
        for (int j = 0; j < hashtags; j++)
        {
            printf("#");
        }

        printf("\n");
    }

}
