#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

bool validate_key(string key);


int main(int argc, string argv[])
{
    if (argc !=2 || !validate_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
   int k = atoi(argv[1]);
   
   string plaintext = get_string("plaintext: ");
   
   printf("ciphertext: ");
   for (int i=0; i< strlen(plaintext); i++)
   {
       char c = plaintext[i];
       if (isalpha(c))
       {
           char b = 'A';
           if (islower(c))
           b = 'a';
           printf("%c", (c-b+k) % 26 + b);
       }
       else 
       printf("%c", c);
   }
    printf("\n");
   return 0;
}


// check for valid input
bool validate_key(string key)
{
    for (int i=0; i< strlen(key); i++)
    {
      
      if (!isdigit(key[i]))
      
          return false;
      


    }
   return true;
}
