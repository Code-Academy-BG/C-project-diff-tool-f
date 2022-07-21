#include "UI.h"
#include <stdio.h>

void displayResult(Differences *result)
{
    if (result->isSame)
    {
        printf("Files are identical.");
    }
    else
    {
        for (int i = 0; i < result->maxLines; i++)
        {
            if (result->arr[i] == 0)
            {
                printf("Left  %d : %s\n", i + 1, result->leftFile->arrayOfCurrentFile[i]);
                printf("Right %d : %s\n", i + 1, result->rightFile->arrayOfCurrentFile[i]);
            }
            else if (result->arr[i] == -1)
            {
                printf("Left  %d : %s\n", i + 1, result->leftFile->arrayOfCurrentFile[i]);
            }
            else if (result->arr[i] == -2)
            {
                printf("Right %d : %s\n", i + 1, result->rightFile->arrayOfCurrentFile[i]);
            }
        }
    }
}