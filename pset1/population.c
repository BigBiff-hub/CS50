#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int n, i, m, b, d;
    do
    {
         n = get_int("Start Size of llama pop: ");
    }
     while (n < 9);
    // TODO: Prompt for end size
 
     do
    {
      m = get_int("End Size of llama pop: ");
    }
     while (m < n);
    // TODO: Calculate number of years until we reach threshold
     for(i=0; n<m; i++)
    {
        b = n/3;
        d = n/4;
        n = n+b -d;
    }
    // TODO: Print number of years
    {
    printf("Years: %i\n", i);
    }
}