#include "Compare.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

/**
 * Return bool answear. True- if files are equal and False- if files are different.
 * @param leftFile - the first file we want to compare
 * @param rightFile - the second file we want to compare
 */
Differences *compareContents(FileContents *leftFile, FileContents *rightFile)
{
    int maxLines = MAX(leftFile->lineNumber, rightFile->lineNumber);
    int minLines = MIN(leftFile->lineNumber, rightFile->lineNumber);
    Differences *result = fillResult(leftFile, rightFile, maxLines);
    fillArrDiffFiles(result, minLines);
    return result;
}

/**
 * Return filled structure.
 * @param leftFile - the first file
 * @param rightFile - the second file
 * @param maxLines - the max lines

 */
Differences *fillResult(FileContents *leftFile, FileContents *rightFile, int maxLines)
{
    Differences *result = (Differences *)malloc(sizeof(Differences));
    result->leftFile = leftFile;
    result->rightFile = rightFile;
    result->isSame = true;
    result->arr = initDifferencesArr(maxLines);
    result->maxLines = maxLines;
    return result;
}

/**
 * Function that init (int *arr from Differences struct).
 * @param result - the structure with files
 * @param size - size of numbers
 */
int *initDifferencesArr(int maxSize)
{
    int *temp = (int *)malloc(sizeof(int) * maxSize);
    return temp;
}

/**
 * Function that fill (Differences->arr) with 0-sign for different files,
 * every time when find different line. And after that with:
 *  0 - if left line is different than right line
 *  1 - if left line  and  right line are same
 * -1 - if left file is large
 * -2 - if right file is large
 * @param result - the structure with files
 * @param minLines - the min lines
 */
void fillArrDiffFiles(Differences *result, int minLines)
{
    for (int i = 0; i < minLines; i++)
    {
        if (strcmp(result->leftFile->arrayOfCurrentFile[i], result->rightFile->arrayOfCurrentFile[i]) != 0)
        {
            *(result->arr + i) = 0;
            result->isSame = false;
        }
        else
        {
            *(result->arr + i) = 1;
        }
    }

    if (result->leftFile->lineNumber < result->rightFile->lineNumber)
    {
        for (int i = minLines; i < result->rightFile->lineNumber; i++)
        {
            *(result->arr + i) = -2;
        }
        result->isSame = false;
    }
    else if (result->leftFile->lineNumber > result->rightFile->lineNumber)
    {
        for (int i = minLines; i < result->leftFile->lineNumber; i++)
        {
            *(result->arr + i) = -1;
        }
        result->isSame = false;
    }
}
