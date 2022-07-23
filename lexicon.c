/**
 * Implementation file for lexicon.h
 * Opens a file, populates a list of strings, parses information from it, and chooses a word from that list to be used as a guess.
 * @file lexicon.c
 * @author your name (you@domain.com)
 *
 */
#include "lexicon.h"
#include "io.h"
/** Large prime multiplier used to choose a word pseudo-randomly. */
#define MULTIPLIER 4611686018453

char wordList[WORD_LIMIT][WORD_LEN + 1];

long count;

void readWords(char const filename[])
{
    FILE *strm = fopen(filename, "r");
    if (!strm)
    {
        fprintf(stderr, "Can't open word list: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    bool con = true;
    count = 0;
    while (con)
    {
        if (count == WORD_LIMIT)
        {
            fprintf(stderr, "Invalid word file\n");
            exit(EXIT_FAILURE);
        }
        con = readLine(strm, wordList[count], WORD_LEN);

        count++;
    }

    count--;
    fclose(strm);
}

void chooseWord(long int seed, char word[])
{
    long index = (seed % count) * MULTIPLIER % count;

    strcpy(word, wordList[index]);
}

bool inList(char const word[])
{

    for (int i = 0; i < count; i++)
    {

        if (strcmp(wordList[i], word) == 0)
        {

            return true;
        }
    }
    return false;
}