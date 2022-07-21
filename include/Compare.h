#ifndef CODE_ACADEMY_DIFF_TOOL_COMPARE_H
#define CODE_ACADEMY_DIFF_TOOL_COMPARE_H

#include <stdbool.h>
#include "FileHandler.h"

typedef struct Differences
{
    FileContents *leftFile;
    FileContents *rightFile;
    int *arr;
    int maxLines;
    bool isSame;
} Differences;

Differences *compareContents(FileContents *leftFile, FileContents *rightFile);
Differences *fillResult(FileContents *leftFile, FileContents *rightFile, int maxLines);
int *initDifferencesArr(int maxLines);
void fillArrDiffFiles(Differences *result, int minLines);

#endif
