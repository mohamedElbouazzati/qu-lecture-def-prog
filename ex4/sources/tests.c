#include "gestion-chaines.h"
#include "gestion-fichiers.h"

#include <stdio.h>
#include <string.h>

size_t MAXLEN = 2048;

int main(int argc, char * argv[]) {
    (void) argc;
    (void) argv;

    const char * rr    = "qfg\ngrg E   \n ISHFEKJHF qfe \x1f\x10 \nkqzeu   ";
    const char * rrr[] = {"qfg", "grg E", " ISHFEKJHF qfe", "kqzeu"};

    size_t nb_lines = 0;

    char ** lrr = extract_line(rr, &nb_lines);
    (void) lrr;

    if (nb_lines != 4) {
        printf("extract_lines : FAILURE\n");
        return 1;
    } else {
        printf("extract_lines : SUCCESS\n");
    }

    for (size_t i = 0; i < nb_lines; i++) {
        const char * line     = lrr[i];
        char *       result   = NULL;
        const char * expected = rrr[i];

        size_t len = trim_string_adv(line, &result, strlen(line));

        if (len != strlen(result)) {
            printf("trim_string_adv size : FAILURE\n");
            return 1;
        } else {
            printf("trim_string_adv size : SUCCESS\n");
        }

        int res_test1 = strcmp(result, expected);
        if (!res_test1) {
            printf("line %s -> %s : SUCCESS\n", line, result);
        } else {
            printf("line %s -> %s : FAILURE\n", line, result);
            return 1;
        }

        if (result != NULL) {
            free(result);
        }

        char * res2 = trim_string_base(line);

        int res_test2 = strcmp(res2, expected);
        if (!res_test2) {
            printf("line %s -> %s : SUCCESS\n", line, result);
        } else {
            printf("line %s -> %s : FAILURE\n", line, result);
            return 1;
        }

        if (res2 != NULL) {
            free(res2);
        }
    }

    return 0;
}
