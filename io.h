/**
 * Header file containing declarations and macros for io.c.
 * Uses terminal characters to change the colors of outputed characters.
 *
 * @file io.h
 * @author Ramon Mayo (rmmayo@ncsu.edu)
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/** Maximum lengh of a word on the word list. */
#define WORD_LEN 5

/** Maximum number of words on the word list. */
#define WORD_LIMIT 100000

/**
 * Reads a line of characters from an already open file stream.
 * If a read string of characters is not of length n, or if there are duplicate strings, the file is invalid and the program exits with an exit code of 1.
 *
 * @param fp The already opened file stream.
 * @param str The string the read line will be placed into.
 * @param n The length of the read line.
 * @return true if the line was read successfully
 * @return false if the line was not read, or if it hit EOF.
 */
bool readLine(FILE *fp, char str[], int n);

/**
 * Changes the terminal color to green.
 *
 */
void colorGreen();

/**
 * Changes the terminal color to yellow.
 *
 */
void colorYellow();

/**
 * Changes the terminal color to its default.
 *
 */
void colorDefault();
/**External function declaration.*/
extern bool inList(char const word[]);
