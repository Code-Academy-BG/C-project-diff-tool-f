#include "FileHandler.h"
#include <stdlib.h>
#include <string.h>

FileContents *readFile(const char *filePath)
{
    FILE *file;
    file = fopen(filePath, "r");
    if (file == NULL)
    {
        printf("This file is not exist !");
    }

    int maxLines = 10;
    char buffer[1024];
    FileContents *fileContent = (FileContents *)malloc(sizeof(FileContents));
    fileContent->arrayOfCurrentFile = (char **)malloc(sizeof(char *) * maxLines);
    fileContent->lineNumber = 0;
    while (fgets(buffer, sizeof(buffer), file))
    {

        if (fileContent->lineNumber == maxLines)
        {
            maxLines = maxLines * 2;
            fileContent->arrayOfCurrentFile = (char **)realloc(fileContent->arrayOfCurrentFile, sizeof(char *) * maxLines);
        }
        fileContent->arrayOfCurrentFile[fileContent->lineNumber] = (char *)malloc(sizeof(char) * (strlen(buffer)));
        strncpy(fileContent->arrayOfCurrentFile[fileContent->lineNumber], buffer, strlen(buffer) - 1);
        fileContent->arrayOfCurrentFile[fileContent->lineNumber][strlen(buffer) - 1] = '\0';
        fileContent->lineNumber++;
    }
    fileContent->arrayOfCurrentFile[fileContent->lineNumber] = "\0";
    fileContent->lineNumber += 1;

    fclose(file);
    return fileContent;
}