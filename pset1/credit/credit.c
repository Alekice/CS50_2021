#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long cardNumber = get_long("Number: ");

    long cardNumberSum1 = cardNumber;
    long cardNumberSum2 = cardNumber;

    int every1digit;
    int sum1;

    for (sum1 = 0; sum1 < cardNumberSum1; sum1 = sum1 + every1digit)
    {
        every1digit = cardNumberSum1 % 10;
        cardNumberSum1 /= 100;
    }

        // printf("%i\n", sum1);

    int every2digit;
    int twice;
    int sum2;

    for (sum2 = 0; sum2 < cardNumberSum2; sum2 = sum2 + twice)
    {
        every2digit = (cardNumberSum2 % 100 / 10);
        twice = every2digit * 2;
        if (twice > 9)
        {
            twice = (twice / 10) + (twice % 10);
        }
        cardNumberSum2 /= 100;
    }

        // printf("%i\n", sum2);

    int total = sum1 + sum2;
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        main();
    }
    else
    {

        long first2digits = cardNumber;
        do
        {
            first2digits /= 10;
        }
        while (first2digits > 99);


        if (first2digits == 34 || first2digits == 37)
        {
            printf("American Express\n");
        }
        else if (first2digits == 51 || first2digits == 52 || first2digits == 53 || first2digits == 54 || first2digits == 55)
        {
            printf("MasterCard\n");
        }
        else if (first2digits / 10 == 4)
        {
            printf("Visa\n");
        }
        else
        {
            printf("INVALID\n");
            main();
        }
    }

    // int digits;

    // for (digits = 0; cardNumber > 0; digits++)
    // {
    //     cardNumber = cardNumber / 10;
    // }

    //     printf("%i\n", digits);



}
