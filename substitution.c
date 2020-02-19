#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool valid = true;
string ciphertext;

//argv = cipherbcdefghijklmnopqrstuvwxyz
//argc = what string #

int main(int argc, string argv[])
{
    //checks if there is a command line argument, if so continue
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        valid = false;
    }
    //checks if valid and if so if there are 26 characters, if so continue
    if (valid == true && (strlen(argv[1]) != 26))
    {
        printf("Key must contain 26 characters.\n");
        valid = false;
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
        
        for(int c = 0; text[0][c] != '\0'; c++)
        {   //checks if user text is alphabetic (should make a function)
            if (text[0][c] >= 65 && text[0][c] <= 90)
            {
                for(int d = 0; d < 26; d++)
                {
                    //determines what number in the alphabet number is
                    if (text[0][c] == abcup[0][d])
                    {
                        text[0][c] = argv[1][d];
                        
                    }
                }
            }
            if (text[0][c] >= 97 && text[0][c] <= 122)
            {
                for (int e = 0; e < 26; e++)
                {
                    if (text[0][c] == abclow[0][e])
                    {
                        text[0][c] = argv[1][e];
                    }
                }
                
            }
        }
        printf("ciphertext: %s\n", text[0]);

    }


}


