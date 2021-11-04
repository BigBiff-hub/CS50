#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main(void)
{
    string text = get_string("Text: ");
    int letters = 0,  words = 1,  sentences = 0;


   //iterate over the string to get words letters and sentences y
    for (int i = 0; i < strlen(text); i++)
    {
       if (isalpha(text[i]))
       {
           letters++;
       }
       else if (isspace(text[i]))
       {
           words++;
       }
       else if (text[i] == '!' || text[i] == '.' || text[i] == '?')
       {
           sentences++;
       }
    }
    // to retrive grade index

    float g = 0.0588 * (100 * (float) letters / (float) words) - 0.296 * (100 * (float) sentences / (float) words) - 15.8;
    if (g < 16 && g >= 0)
    {
        printf("Grade %i\n", (int) round(g));
    }
    else if (g >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }

}