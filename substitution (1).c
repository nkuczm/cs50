#include <cs50.h>
#include <stdio.h>
#include <string.h>

//if false, error
bool valid = true;
string ciphertext[1];

int main(int argc, string argv[])
{
    //checks if there is a command line argument, if so continue
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        valid = false;
        return 1;
    }
    //checks if valid and if so if there are 26 characters, if so continue
    if (valid == true && (strlen(argv[1]) != 26))
    {
        printf("Key must contain 26 characters.\n");
        valid = false;
        return 1;
    }
    //checks if still valid then if so if all characters are alphabetic
    if (valid == true)
        for (int i = 0; i < 26; i++)
        {
            if ((argv[1][i] >= 65 && argv[1][i] <= 90) || (argv[1][i] >= 97 && argv[1][i] <= 122))
            {
                valid = true;
            }
            else
            {
                printf("Key must only contain alphabetic characters.\n");
                valid = false;
                return 1;
            }
        }
    //checks if still valid, then if so if there are no repeated characters
    if (valid == true)
    {
        for (int a = 0; a < 26; a++)
        {
            for (int b = 0; b < 26; b++)
            {
                if ((valid == true) && (a != b) && ((argv[1][a] == argv[1][b]) || (argv[1][a] == (argv[1][b] + 32))
                                                    || (argv[1][a] == (argv[1][b] + 32))))
                {
                    printf("You have repeated a character\n");
                    valid = false;
                    return 1;
                }
            }
        }
    }

    if (valid == true)
    {
        //takes user text
        string plaintext = get_string("plaintext: ");
        string text[1];
        text[0] = plaintext;

        string abclow[1];
        abclow[0] = "abcdefghijklmnopqrstuvwxyz";
        string abcup[1];
        abcup[0] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        //starts loop that goes through each letter from input until it is found what letter it is and it is changed
        for (int c = 0; text[0][c] != '\0'; c++)
        {   
            //changes chracter if uppercase
            if (text[0][c] >= 65 && text[0][c] <= 90)
            {
                //starts a for loop going through each normal alphabet letter to see what letter input is in seq.
                for (int d = 0; d < 26; d++)
                {
                    //determines what number in the alphabet number is
                    if (text[0][c] == abcup[0][d])
                    {
                        //checks to make the changed text will be same case
                        if (argv[1][d] >= 65 && argv[1][d] <= 90)
                        {
                            text[0][c] = argv[1][d];
                            d = 26;
                            
                        }
                        else
                        {
                            //switches the output case to uppercase if key is lowercase
                            text[0][c] = (argv[1][d] - 32);
                            d = 26;
                        }
                    }
                }
            }
            //changes character if lowercase
            if (text[0][c] >= 97 && text[0][c] <= 122)
            {
                for (int e = 0; e < 26 ; e++)
                {
                    if (text[0][c] == abclow[0][e])
                    {
                        //checks to make sure output will be same case, if not will chang
                        if (argv[1][e] >= 97 && argv[1][e] <= 122)
                        {

                            text[0][c] = argv[1][e];
                            e = 26;
                        }
                        else
                        {
                            //switches the case to lowercase if key is uppercase
                            text[0][c] = (argv[1][e] + 32);
                            e = 26;
                        }
                    }
                }

            }
        }
        //output text
        printf("ciphertext: %s\n", text[0]);
        return 0;

    }


}

