// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;
int total_words = 0;
unsigned int hash_value;
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{

    hash_value = hash(word);
    //get into linked list  
    node *cursor = table[hash_value];
    //iterate over linked list 
    while (cursor != NULL)
    {
        //check if the word matches
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        //make cursor move to next node
        cursor = cursor->next;
    }
     return false;
}

    


// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO hash function: http://www.cse.yorku.ca/~oz/hash.html djb2 Dan Bernstein
    unsigned long hash = 5381;
    int c;
    while ((c = toupper(*word++)))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % N;
    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //LOAD DICTIONARY FILE IN READ MODE
    FILE *file = fopen(dictionary, "r");
    //check base case
    if(!file)
    {
        return false; //unable to open file
    }
    //readone word at a time from the file pointer

    char word[LENGTH + 1];//define buffer
    while(fscanf(file, "%s", word)!=EOF)
    {
        //create new node to store words
        node *new_n = malloc(sizeof(node));
        //check base case
        if(new_n==NULL)
        {
            return false;
        }
        //copy word into node
        strcpy(new_n->word, word);
        new_n->next =NULL;
        //GET HASH index
        int index = hash(word);
        if(table[index]==NULL)
        {
            table[index] = new_n;
        }
        else
        {
            new_n->next = table[index];
            table[index] = new_n;
        }
        total_words++;
    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO

    return total_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // free up memory from linked list 
    for(int i = 0; i<N; i++)
    {
        node *head = table[i];
        node *cursor = head;
        node *temp = head;
        while(cursor != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
    }
    return true;
}
