#include "Compare.h"
#include "FileHandler.h"
#include "UI.h"
#include "FreeMemory.h"
#include <stdio.h>

struct Args
{
    const char *leftFilePath;
    const char *rightFilePath;
};

struct Args parseArguments(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    struct Args args = parseArguments(argc, argv);

    FileContents *leftFile = readFile(args.leftFilePath);
    FileContents *rightFile = readFile(args.rightFilePath);

    Differences *result = compareContents(leftFile, rightFile);

    displayResult(result);
    freeMemoryFileContents(leftFile);
    freeMemoryFileContents(rightFile);
    freeMemoryDifferences(result);
    return 0;
}

struct Args parseArguments(int argc, char *argv[])
{
    struct Args arguments;
    if (argc >= 2)
    {
        arguments.leftFilePath = argv[1];
        arguments.rightFilePath = argv[2];
        return arguments;
    }
    else
    {
        printf("Not enough arguments");
        arguments.leftFilePath = NULL;
        arguments.rightFilePath = NULL;
        return arguments;
    }
}