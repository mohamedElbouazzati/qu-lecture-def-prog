#include "gestion-chaines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** extract_line(const char * str, size_t * res_nb_lines) {
    if (str == NULL) {
        return (char **) -1;
    }

    int nb_lines = 0;
    for (const char * ptrc = str; ptrc != NULL; ptrc = strchr(ptrc, '\n')) {
        nb_lines++;
        if (ptrc != NULL)
            ptrc++;
    }

    char **      STR      = (char **) malloc(nb_lines * sizeof(char *));
    int          max_size = strlen(str);
    int          i        = 0;
    const char * optrc    = str;
    while (optrc != NULL) {
        const char * ptrc = strchr(optrc, '\n');

        int size = ptrc != NULL ? ptrc - optrc : (str + max_size) - optrc;
        STR[i]   = (char *) malloc(size + 1 * sizeof(char));
        (void) strncpy(STR[i], optrc, size);
        STR[i++][size] = 0;

        optrc = ptrc != NULL ? ++ptrc : NULL;
    }

    *res_nb_lines = nb_lines;

    return STR;
}

size_t trim_string_adv(const char * to_trim, char ** result, size_t size) {
    int i                   = size;
    int dernier_char_trouve = 0;

    if (result == NULL) {
        return -1;
    }

    char * STR = NULL;
    if (*result == NULL) {
        STR     = (char *) malloc(size + 1 * sizeof(char));
        *result = STR;
    } else {
        STR = *result;
    }

    do {
        i -= 1;
        char c = to_trim[i];
        if (c >= 33) {
            dernier_char_trouve = 1;
        }
    } while (!dernier_char_trouve && i > 0);

    if (dernier_char_trouve) {
        (void) strncpy(STR, to_trim, i + 1);
        STR[i + 1] = 0;
    }

    return i + 1;
}

char * trim_string_base(const char * to_trim) {
    if (to_trim == NULL) {
        return (char *) -1;
    }

    const int size         = strlen(to_trim);
    int       endstr_found = 0;

    char * STR = (char *) malloc((size + 1) * sizeof(char));

    int i = size;
    do {
        i -= 1;
        char c = to_trim[i];
        if (c >= 33) {
            endstr_found = 1;
        }
    } while (!endstr_found && i > 0);

    if (endstr_found) {
        (void) strncpy(STR, to_trim, i + 1);
        STR[i + 1] = 0;
    }

    return STR;
}
