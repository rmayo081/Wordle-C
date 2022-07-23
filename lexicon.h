/**
 * Header file containing macros and declarations for lexicon.c.
 * Reads words from a given input file, determine what words are in the file, and chooses a potentially random word from the list.
 * @file lexicon.h
 * @author Ramon Mayo (rmmayo@ncsu.edu)
 *
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/** Maximum lengh of a word on the word list. */
#define WORD_LEN 5

/** Maximum number of words on the word list. */
#define WORD_LIMIT 100000
/*variable containing an array of words.*/
char wordList[WORD_LIMIT][WORD_LEN + 1];
/**The number of words in the list of words.*/
long count;
/**
 * Opens a given file, reads from it line by line, and stores its strings into wordList.
 *
 * @param filename the given filename.
 */
void readWords(char const filename[]);
/**
 * Selects a word from wordList based on the seed value then stores the chosen string into the word parameter.
 *
 * @param seed the value used to select the index of a word from wordList.
 * @param word the array that will hold the resulting string.
 */
void chooseWord(long seed, char word[]);
/**
 * Determines if a given string is present in the wordList array.
 *
 * @param word the word to be searched for in the array.
 * @return true if the word is in the list.
 * @return false if the word is not in the list.
 */
bool inList(char const word[]);
