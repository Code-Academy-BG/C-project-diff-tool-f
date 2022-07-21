#ifndef CODE_ACADEMY_DIFF_TOOL_FILE_HANDLER_H
#define CODE_ACADEMY_DIFF_TOOL_FILE_HANDLER_H

#include<stdio.h>
#define MAX_CHARS 200

typedef struct FileContents{
    char ** arrayOfCurrentFile;
    int lineNumber;
}FileContents;

FileContents * readFile(const char *filePath);

#endif
