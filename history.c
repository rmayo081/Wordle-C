#include "history.h"

void updateScore(int guessCount)
{
    int hist[10];

    FILE *op = fopen("scores.txt", "r");
    if (!op)
    {

        for (int i = 0; i < 10; i++)
        {
            hist[i] = 0;
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            fscanf(op, "%d", &hist[i]);
        }
    }
    if (op)
        fclose(op);

    if (guessCount >= 10)
    {
        hist[9]++;
    }
    else
    {
        switch (guessCount)
        {
        case 1:
            hist[0]++;
            break;
        case 2:
            hist[1]++;
            break;
        case 3:
            hist[2]++;
            break;
        case 4:
            hist[3]++;
            break;
        case 5:
            hist[4]++;
            break;
        case 6:
            hist[5]++;
            break;
        case 7:
            hist[6]++;
            break;
        case 8:
            hist[7]++;
            break;
        case 9:
            hist[8]++;
            break;
        default:
            break;
        }
    }

    for (int i = 1; i <= 10; i++)
    {
        printf((i != 10) ? "%2d  :%5d\n" : "%2d+ :%5d\n", i, hist[i - 1]);
    }

    FILE *up = fopen("scores.txt", "w");
    for (int i = 0; i < 10; i++)
    {
        fprintf(up, (i == 9) ? "%d" : "%d ", hist[i]);
    }
    fprintf(up, "\n");

    fclose(up);
}