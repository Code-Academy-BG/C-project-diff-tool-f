#include "FreeMemory.h"
#include <stdlib.h>

void freeMemoryFileContents(FileContents *file)
{
    for (int i = 0; i < file->lineNumber - 1; i++)
    {
        free(file->arrayOfCurrentFile[i]);
    }
    free(file->arrayOfCurrentFile);
    free(file);
}

void freeMemoryDifferences(Differences *result)
{
    free(result->arr);
    free(result);
}
