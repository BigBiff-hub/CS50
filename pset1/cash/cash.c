#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main()
{
    float dollars;
    // TODO: Prompt for change needed 
    do
    {
    dollars = get_float("No. of coins owed customer: ");
    }
     while (dollars < 0);
     
     int cent = round(dollars * 100);
    
     int coinage = 0;
    // method in order
    // input/25 = output
    // input/10 = output
    // input/5 = output
    // input/1 = output
     while(cent !=0)
     {
   
       
       coinage += cent / 25;// devide input
       cent = cent % 25;//get remiander
       //do for 25c
       coinage += cent/10;
       cent %= 10;
       //do for 5c
       coinage += cent/5;
       cent %= 5;
       //do for 1c
       coinage += cent/1;
       cent %= 1;
    }
   
    printf("%d\n", coinage);
    
}