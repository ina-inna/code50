#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>


// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO

    // if name appears in the array of candidates,
        for (int i = 0; i < candidate_count; i++)
        {
        const char *str1 = name;
        const char *str2 = candidates[i].name;
        if (strcasecmp(str1, str2) == 0)

    // if yes, return the index and +1 vote to the candidate with the same name
        {
            candidates[i].votes = candidates[i].votes + 1;
            return true;
        }
        }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // // TODO

    // find the biggest vote
    int index;
    int top_votes = candidates[0].votes;
    for (int i = 1; i < candidate_count; i++)
    {

        if (top_votes < candidates[i].votes)
        {
            top_votes = candidates[i].votes;
        }
        return candidates[i].name;
    }

    printf("%s\n", candidates[i].name);


}