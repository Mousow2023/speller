// Implements a dictionary's functionality

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Keep track of the number of words
int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Hash the word to obtain a hash value
    int index = hash(word);

    // Start with cursor set to the first item of LL
    node *cursor = table[index];
    if (!cursor)
    {
        return false;
    }

    // Keep moving cursor untill get to NULL
    while (cursor != NULL)
    {
        // Compare the word and the current node's word
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }

        // Refresh cursor
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary file
    FILE *infile = fopen(dictionary, "r");
    if (!infile)
    {
        return false;
    }

    // Read strings from the file one at a time
    char bucker[LENGTH + 1];
    while (fscanf(infile, "%s", bucker) != EOF)
    {
        // Create a new node for each word and check for NULL
        node *n = malloc(sizeof(node));
        if (!n)
        {
            fclose(infile);
            return false;
        }
        strcpy(n->word, bucker);

        // Hash word to obtain a hash value
        int index = hash(bucker);

        // Increment the number of words
        word_count++;

        // Insert node into the hash table
        if (table[index] == NULL)
        {
            n->next = NULL;
        }
        else
        {
            n->next = table[index];
        }

        table[index] = n;
    }

    fclose(infile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // Iterate over the hash table
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            // Secure the adress of the current node
            node *temp = cursor;

            // Move the cursor to the next node
            cursor = cursor->next;
            // Free the current node
            free(temp);
        }
    }

    return true;
}
