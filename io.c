#include "io.h"

FILE *openFile(char *filename, char *mode) {
    FILE *opened = fopen(filename, mode);
    if (!opened) {
        printf("The file %s could not be opened.", filename);
        exit(1);
    }

    return opened;
}

long getSize(FILE *fp) {
    long original = ftell(fp);

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

    fseek(fp, original, SEEK_SET);
    return size;
}

FILE **openFiles (char **filenames, char **modes, int count) {
    FILE **files = (FILE **) malloc(sizeof (FILE *) * count);

    for (int i = 0; i < count; i++) {
        files[i] = openFile(filenames[i], modes[i]);
    }

    return files;
}

void closeFiles (FILE **files, int count) {
    for (int i = 0; i < count; i++) {
        fclose(files[i]);
    }

    free(files);
}