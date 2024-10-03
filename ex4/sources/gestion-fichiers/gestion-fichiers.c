#include "gestion-fichiers.h"

#include <stdio.h>
#include <string.h>

#include "gestion-chaines.h"

#define BUF_SIZE 65536

char ** read_file_lines(const char * path, size_t * nb_lines) {
    char * line_file = malloc(BUF_SIZE * sizeof(char));
    size_t read      = 0;

    FILE * file = fopen(path, "r");
    if (file == NULL) {
        char str[64];
        sprintf(str, "fopen in %s line %d", __FILE__, __LINE__ - 3);
        perror(str);
        exit(1);
    }

    while (1) {
        read += fread(line_file + read, 1, BUF_SIZE, file);
        if (!feof(file) && !ferror(file)) {
            line_file = realloc(line_file, read + BUF_SIZE);
        } else if (ferror(file)) {
            char str[64];
            sprintf(str, "fread in %s line %d", __FILE__, __LINE__ - 5);
            perror(str);
            exit(1);
        } else {
            break;
        }
    }

    line_file[read + 1] = 0;

    char ** lines = extract_line(line_file, nb_lines);
    free(line_file);

    int res = fclose(file);
    if (res == EOF) {
        char str[64];
        sprintf(str, "fclose in %s line %d", __FILE__, __LINE__ - 3);
        perror(str);
        exit(1);
    }

    return lines;
}

int write_file_lines(const char * path, const char ** lines, size_t nb_lines) {
    FILE * file = fopen(path, "w");
    if (file == NULL) {
        char str[64];
        sprintf(str, "fopen in %s line %d", __FILE__, __LINE__ - 3);
        perror(str);
        exit(1);
    }

    for (size_t i = 0; i < nb_lines - 1; i++) {
        const char * line = lines[i];
        (void) fwrite(line, 1, strlen(line), file);
        (void) fwrite("\n", 1, 1, file);

        if (ferror(file)) {
            char str[64];
            sprintf(str, "fread in %s line %d", __FILE__, __LINE__ - 5);
            perror(str);
            exit(1);
        }
    }

    const char * line = lines[nb_lines - 1];
    (void) fwrite(line, 1, strlen(line), file);
    if (ferror(file)) {
        char str[64];
        sprintf(str, "fread in %s line %d", __FILE__, __LINE__ - 3);
        perror(str);
        exit(1);
    }

    int res = fclose(file);
    if (res == EOF) {
        char str[64];
        sprintf(str, "fclose in %s line %d", __FILE__, __LINE__ - 3);
        perror(str);
        exit(1);
    }

    return 0;
}