#include "io.h"

void compareFile (char *src, char *dest);

int main (int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please input 2 parameters.\n");
        exit(1);
    }

    compareFile(argv[1], argv[2]);
}

void compareFile (char *src, char *dest) {
    char *names[] = {src, dest};
    char *modes[] = {"r", "r"};

    FILE **files = openFiles(names, modes, 2);
    int diffs = 0;

    int at = 0;
    while (!feof(files[0]) && !feof(files[1])) {
        char a = getc(files[0]);
        char b = getc(files[1]);
        at++;

        if (a != b) {
            if (a > 32 && a < 127 && b > 32 && b < 127)
                printf("@position %d: %s%c%s%c%s\n", at, ANSI_COLOR_RED, b, ANSI_COLOR_GREEN, a, ANSI_COLOR_RESET);
            diffs++;
        }
    }

    if (diffs == 0) {
        printf("No differences.\n");
    } else {
        printf("%d Differences.\n", diffs);
    }
    closeFiles(files, 2);
}