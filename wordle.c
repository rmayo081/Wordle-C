/**
 *Main component file of the wordle program.
 *Expects command line arguments to specify the word list file and seed number for word selection.
 *Takes user guesses and outputs words in various colors depending on what characters the user guessed correctly.
 * @file wordle.c
 * @author Ramon Mayo (rmmayo@ncsu.edu)
 *
 */
#include "lexicon.h"
#include "history.h"
#include "io.h"
#include <time.h>

extern char wordList[WORD_LIMIT][WORD_LEN + 1];

extern long count;

/**
 * Determines if a given character is present in a given string, and if that character has already been previously guessed.
 *
 * @param word The string that may, or may not contain the character.
 * @param ch The character checked for.
 * @param j A boolean array where each index indicates if a specfic character index in word has already been correctly guessed.
 * @param k A boolean array where each index indicates if a specific character has been guessed correctly, but not at the correct index.
 * @return true if the character is in the string and has not been guessed.
 * @return false otherwise.
 */
bool contains(char const word[], char const ch, bool const j[], bool k[])
{
    int len = strlen(word); // length of the word
    for (int i = 0; i < len; i++)
    { // check every character in word, if it is present and has not been guessed, return true.
        if (word[i] == ch)
        {
            if (!j[i] && !k[i])
            {
                k[i] = true;
                return true;
            }
        }
    }
    return false;
}

/**
 * Main function of the program. Uses command line arguments to select the file that contains the word list, and a seed integer to choose a word from that list.
 * If no seed number is given, the current time is used as the seed for a random number.
 * Takes use input for word guesses, if an input is too short, too long, or not in the given word list then the guess is invalid and not counted.
 * If a user guesses a letter correctly, but not the correct position, that character appears yellow in standard output.
 * If a user guesses a letter and position correctly, that character appears green in standard output.
 * The number of guesses is recorded and used to build a score history file.
 * Type "quit" into standard input to exit the program early.
 *
 * @param argc The number of command line arguments.
 * @param argv The string array of command line arguments
 * @return 0 if the program exits without errors.
 */
int main(int argc, char *argv[])
{
    int guessCnt = 0;         // number of user guesses
    char guess[WORD_LEN + 1]; // character array for user guess.
    char word[WORD_LEN + 1];  // character array for word that will be guessed.

    bool guessflag = false; // flag to indicate if the word has been guessed correctly.

    readWords(argv[1]); // read the list of words into an array.

    if (argc == 3)
    { // if a seed number was provided, use it to choose a word, otherwise use time.
        chooseWord(atoi(argv[2]), word);
    }
    else if (argc == 2)
    {
        chooseWord(time(NULL), word);
    }

    while (!guessflag)
    {
        guessCnt++;

        int m = scanf("%s", guess);
        if (m == EOF || strcmp(guess, "quit") == 0)
        { // if user enters "quit", the program exits.
            printf("The word was \"%s\"\n", word);
            exit(EXIT_SUCCESS);
        }
        int len = strlen(guess);
        while (m != 1 || len != 5 || !inList(guess))
        { // If the length of the word is invalid, or the guess is invalid, user must enter a new guess.
            if (m == EOF)
            {
                break;
            }
            else if (strcmp(guess, "quit") == 0)
            {
                break;
            }
            printf("Invalid guess\n");
            m = scanf("%s", guess);

            len = strlen(guess);
        }

        if (m == EOF || strcmp(guess, "quit") == 0)
        {
            printf("The word was \"%s\"\n", word);
            exit(EXIT_SUCCESS);
        }

        if (strcmp(guess, word) == 0)
        { // If the word was gueesed correctly
            guessflag = true;
        }

        else
        {
            // int j = 0;
            bool green[WORD_LEN];
            bool yel[WORD_LEN];
            int curCol = 0; // 0 is default, 1 is yellow, 2 is green.

            for (int i = 0; i < WORD_LEN; i++)
            {
                yel[i] = false;
                green[i] = false;
            }

            for (int i = 0; i < WORD_LEN; i++)
            {

                if (word[i] == guess[i])
                {
                    green[i] = true;
                }
            }

            for (int i = 0; i < WORD_LEN; i++)
            {
                if (word[i] == guess[i])
                {
                    if (curCol != 2)
                    {
                        colorGreen();
                        curCol = 2;
                    }
                    putchar(guess[i]);
                }
                else if (contains(word, guess[i], green, yel))
                {
                    if (curCol != 1)
                    {
                        colorYellow();
                        curCol = 1;
                    }
                    putchar(guess[i]);
                }
                else
                {
                    if (curCol != 0)
                    {
                        colorDefault();
                        curCol = 0;
                    }
                    putchar(guess[i]);
                }
            }
            if (curCol != 0)
            {
                colorDefault();
                curCol = 0;
            }
            putchar('\n');
        }
    }

    printf((guessCnt == 1) ? "Solved in %d guess\n" : "Solved in %d guesses\n", guessCnt);
    updateScore(guessCnt);
    return EXIT_SUCCESS;
}