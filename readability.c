#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // Declaring variables (words, letter, and sentences)
    float letters = 0, words = 1, sentences = 0;

    // get string from user
    string text = get_string("Please insert the text you want to assess here: ");

    // Set i to zero and determine string's length
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }

        {

            if (isspace(text[i]))
            {
                words++;
            }


            {
                if (text [i] == '.' || text[i] == '?' || text[i] == '!')

                {
                    sentences ++;
                }
            }
        }
    }

    // Calculations for the Readability test is the Coleman-Liau index
    float l = letters / words * 100;
    float s = sentences / words * 100;
    float index0 = .0588 * l;
    float index1 = 0.296 * s;
    float indexResult = index0 - index1 - 15.8;

    // Adding conditions to determine grade levels
    if (indexResult < 1)
    {
        printf("Before Grade 1\n");
    }

    // If grade level is not 1 then check for second condition
    else if (indexResult > 16)
    {
        printf("Grade 16+\n");
    }
    // Else if grade level is not 16 then  print 16+
    else
    {
        printf("Grade %g\n", round(indexResult));
    }
}