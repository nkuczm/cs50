#include <cs50.h>
#include <stdio.h>

float words = 0;
float letters = 0;
float sentences = 0;

int main(void)
{
    string text = get_string("Text: ");

    for (int i = 0; text[i] != '\0'; i++)
    {
        //detects all of the letters in the string
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
        }
        //detects all of the spaces (words) in a string, rest are accounted by periods
        if (text[i] == 32)
        {
            words++;
        }
        //determines number of sentences then adds one word if end of all sentences since no more spaces after.
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            if (text[i + 1] == '\0')
            {
                words++;
            }
            sentences++;
        }
    }
    //multiplier is what words needs to be multiplied by to be 100, then multiplied by others
    float multiplier = 100 / words;
    //letters per 100 words (L)
    float lpw = letters * multiplier;
    //sentences per 100 words (S)
    float spw = sentences * multiplier;
    //index equation: index = 0.0588 * L - 0.296 * S - 15.8
    float index = .0588 * lpw - .296 * spw - 15.8;

    //categorizes what grade level the index output is
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}