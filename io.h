#pragma once
#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

FILE *openFile(char *filename, char *mode);
long getSize(FILE *fp);
FILE **openFiles (char **filenames, char **modes, int count);
void closeFiles (FILE **files, int count);