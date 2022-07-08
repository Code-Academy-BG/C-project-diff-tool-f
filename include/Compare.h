#ifndef CODE_ACADEMY_DIFF_TOOL_COMPARE_H
#define CODE_ACADEMY_DIFF_TOOL_COMPARE_H

#include <stdbool.h>

#include "FileHandler.h"


typedef bool Differences;

Differences compareContents(const FileContents leftFile,
                            const FileContents rightFile);

#endif // CODE_ACADEMY_DIFF_TOOL_COMPARE_H
