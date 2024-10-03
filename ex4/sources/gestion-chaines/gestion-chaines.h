#ifndef GESTION_CHAINES_H
#define GESTION_CHAINES_H

#include <stdlib.h>

char ** extract_line(const char * str, size_t * res_nb_lines);

size_t trim_string_adv(const char * to_trim, char ** result, size_t size);
char * trim_string_base(const char * to_trim);

#endif // GESTION_CHAINES_H