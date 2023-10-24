// Implements a dictionary's functionality

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
const unsigned int N = 1000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
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
    int final_num = sum % 1000;
    return final_num;

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
        printf("Could not open %s.\n", text);
        return 1
    }

    // read strings from file one at a time -> fscanf(file, "%s", word) -> fscanf will return EOF one it reaches it
    string s;
    while (fscanf(file, "%s", word) != EOF)
            {
                node* n = malloc(sizeof(node))
                    if (n == NULL)
                    {
                        printf("Could not open %s.\n", text);
                        return 1
                    }
            }


    // allocate memory for a new node -> node * n = malloc(sizeof(node))
    // strcpy(n->word, "")

    // hash word to obtain a hash value

    // insert node into hash table at that location -> word(hash number) add to a table(hash number)

    // until EOF

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}