/**
 *Implementation file for io.h.
 * @file io.c
 * @author Ramon Mayo (rmmayo@ncsu.edu)
 */
#include "io.h"
#include <stdio.h>

bool readLine(FILE *fp, char str[], int n)
{
    char newS[WORD_LEN + 1];
    for (int i = 0; i < n; i++)
    {
        char cur = fgetc(fp);

        if (cur >= 'a' && cur <= 'z')
        {
            // printf("here\n");
            newS[i] = cur;
        }
        else if (cur == EOF)
        {
            return false;
        }
        else
        {
            fprintf(stderr, "Invalid word file\n");
            exit(EXIT_FAILURE);
        }
    }
    newS[n] = '\0'; // add a null terminator to the end of the word.
    // inList(), check if the word is already in the list. exit if it is.
    if (inList(newS))
    {
        fprintf(stderr, "Invalid word file\n");
        exit(EXIT_FAILURE);
    }
    getc(fp); // eat the remaining newline character.

    strcpy(str, newS); // copy the string into the parameter

    return true;
}

void colorGreen()
{
    printf("%c%c%c%c%c", 0x1B, 0x5B, 0x33, 0x32, 0x6D);
}

void colorYellow()
{
    printf("%c%c%c%c%c", 0x1B, 0x5B, 0x33, 0x33, 0x6D);
}

void colorDefault()
{
    printf("%c%c%c%c", 0x1B, 0x5B, 0x30, 0x6D);
}