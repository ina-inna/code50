#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins\n");
    }
    else if (score1 == score2)
    {
        printf("Tie\n");
    }
    else
    {
        printf("Player 2 wins\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;
    // define length of the word
    int length = strlen(word);
    // convert each character to nth element in the array points
    for (int i = 0; i < length; i++)
    {
        // get a sum of all elements

        char current_letter = word[i];
        int point_index;
        // int point_index = tolower(current_letter) - 'a';

        if (isupper(current_letter))
        {
             point_index = current_letter - 'A';
        }
        else if (islower(current_letter))
        {
        point_index = current_letter - 'a';
        }

        score += POINTS[point_index];
    }

    return score;
}
