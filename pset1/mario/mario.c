#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size of pyramid
    int h;
    do
    {
         h = get_int("Height of pyramid: ");
    }
     while (h < 1 || h>8);
    // h is a valid input between 1 & 8
    // represents height of pryramid
    
    
    // for loop to print # for each row
    // no of row = no of #
    for(int i=1; i<=h; i++)
    {
        
         //make pyramid right aligned
         for(int k=1; k<=h-i; k++)
         {
           printf(" ");
         }
       
         //print amount of # needed
         for(int j=1; j<=i; j++)
        {
         printf("#");
        }
      printf("\n");
    }
    
    return 0;
}