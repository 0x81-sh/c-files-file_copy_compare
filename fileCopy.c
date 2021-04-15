#include <stdbool.h>
#include "io.h"

void copyFile (char *src, char *dest, bool copyPerChar);

int main (int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please input 2 parameters.\n");
        exit(1);
    }

    copyFile(argv[1], argv[2], true);
}

void copyFile (char *src, char *dest, bool copyPerChar) {
    char *names[] = {src, dest};
    char *modes[] = {"r", "w"};

    FILE **files = openFiles(names, modes, 2);
    int chars = getSize(files[0]) / sizeof (char);

    if (copyPerChar) {
        for (int i = 0; i < chars; i++) {
            fputc(fgetc(files[0]), files[1]);
        }
    } else {
        char *buffer = (char *) malloc (sizeof (char) * chars);

        fread(buffer, chars, 1, files[0]);
        fwrite(buffer, chars, 1, files[1]);

        free(buffer);
    }

    closeFiles(files, 2);
}
