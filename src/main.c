#include "Compare.h"
#include "FileHandler.h"
#include "UI.h"


struct Args
{
    const char *leftFilePath;
    const char *rightFilePath;
};

struct Args parseArguments(int argc, char *argv[]);


int main(int argc, char *argv[])
{
    struct Args args = parseArguments(argc, argv);

    FileContents leftFile = readFile(args.leftFilePath);
    FileContents rightFile = readFile(args.rightFilePath);

    Differences result = compareContents(leftFile, rightFile);

    displayResult(result);

    return 0;
}
