/**
 * Header file that contains declarations and includes for the history.c file.
 * @file history.h
 * @author Ramon Mayo (rmmayo@ncsu.edu)
 * @version 0.1
 * @date 2022-03-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Reads the scores.txt file, if one exists, updates its contents, then prints out the user's score history.
 *
 * @param guessCount The number of guesses to be added to the scores.txt file.
 */
void updateScore(int guessCount);