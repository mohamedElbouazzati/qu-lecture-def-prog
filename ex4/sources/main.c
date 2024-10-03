#include "gestion-chaines.h"
#include "gestion-fichiers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int file_trimmer(const char * file_in, const char * file_out) {

    size_t  nb_lines = 0;
    char ** lines    = read_file_lines(file_in, &nb_lines);

    char ** trimmed_lines = (char **) malloc(nb_lines * sizeof(char *));
    for (size_t i = 0; i < nb_lines; i++) {
        trimmed_lines[i] = NULL;
        trim_string_adv(lines[i], trimmed_lines + i, strlen(lines[i]) + 1);
    }

    int result = write_file_lines(file_out, (const char **) trimmed_lines, nb_lines);

    for (size_t i = 0; i < nb_lines; i++) {
        free(lines[i]);
        free(trimmed_lines[i]);
    }
    free(lines);
    free(trimmed_lines);

    return result;
}

int main(int argc, char * argv[]) {
    if (argc != 3) {
        printf("Need 2 arguments : file_in and file_out");
        return 1;
    }

    const char * file_in  = argv[1];
    const char * file_out = argv[2];
    
    int res = file_trimmer(file_in, file_out);

    return res;
}
