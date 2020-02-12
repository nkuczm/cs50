#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    long reduced = number;
    long digit;
    long sum = 0;
    int valid = 1;

    //printf("%ld\n", number / 100);

    //reduced is reduced number used to find digits
    // I must make a loop that first reduces then takes the remainder then multiplies
    for (; reduced > 0;)
    {   
        //adds every other digit not needed to be multiplied
        digit = reduced % 10;
        sum = sum + digit;
        //reduces the number each loop by dividing by a power of 10
        reduced = reduced / 10;
        //finds the last digit of the reduced digit by dividing by 10 and using remainder
        digit = reduced % 10;
        //multiplies the off digits
        digit = digit * 2;
        //separates numbers of numbers over 10
        if (digit > 9) 
        {
        //the long tens is a number that is two digits long
        long tens = digit;
        tens = tens % 10;
        sum = sum + tens;
        tens = digit;
        tens = tens / 10;
        tens = tens % 10;
        sum = sum + tens;
        }
        //finds sum of digits by multiplying number by two and adding
        else
        {
            sum = sum + digit;
        }
        //reduces number after each iteration to get to next digit
        reduced = reduced / 10;


    }
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        valid = 0;
    }
    //these if statements find what type of card it is
    if (valid == 1 && (number / 10000000000000 == 37 || number / 10000000000000 == 34))
    {
        printf("AMEX\n");
    }
    else if (valid == 1 && (number / 100000000000000 == 51 || number / 100000000000000 == 52 || 
    number / 100000000000000 == 53 || number / 100000000000000 == 54 || number / 100000000000000
    == 55))
    {
        printf("MASTERCARD\n");
    }
    else if (valid == 1 && (number / 1000000000000 == 4 || number / 1000000000000000 == 4))
    {
        printf("VISA\n");
    }
    else if (valid == 1)
    {
        printf("INVALID\n");
    }
}
