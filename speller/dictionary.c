// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int number_of_words;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // turn to hash
    int location = hash(word);
    node* cursor = table[location];

    if (strcasecmp())


    // access linked list at that index

    // traverse linked list looking for that word - strcasecmp

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int sum = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        sum +=toupper(word[i]);
    }
    return sum % N;
   // return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // open a dictionary file -> fopen + check if return value is NULL
    //char *dictionary = (argc == 3) ? argv[1] : DICTIONARY;
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return 1;
    }

    // read strings from file one at a time -> fscanf(file, "%s", word) -> fscanf will return EOF one it reaches it
    number_of_words = 0;
    char *input[LENGTH + 1];
    while (fscanf(file, "%s", input) != EOF)
        {
            // allocate memory for a new node
            node* new_node = malloc(sizeof(node));
                if (new_node == NULL)
                {
                    printf("Memory allocation failed.\n");
                    return 2;
                }
            strcpy(new_node->word, input);

            // hash word to obtain a hash value
            int location = hash(new_node->word);

            // insert node into hash table at that location -> word(hash number) add to a table(hash number)

            new_node->next = table[location]->next;
            table[location] = new_node;

            number_of_words++;
        }
        fclose(file);


    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (number_of_words = 0)
    {
        return 0;
    }
    else
    {
       return number_of_words;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
