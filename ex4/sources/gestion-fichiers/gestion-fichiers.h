#ifndef GESTION_FICHIERS_H
#define GESTION_FICHIERS_H

#include <stdlib.h>

char ** read_file_lines(const char * path, size_t * nb_lines);

int write_file_lines(const char * path, const char ** lines, size_t nb_lines);

#endif // GESTION_FICHIERS_H