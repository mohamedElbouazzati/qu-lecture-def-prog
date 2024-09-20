#include "geo_functions/geo_functions.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  float L = 0.f, H = 0.f;
  if (argc <= 1) {
    L = 48.75f;
    H = 107.6f;
  } else if (argc <= 2) {
    L = strtof(argv[1], NULL);
    H = 107.6f;
  } else if (argc <= 3) {
    L = strtof(argv[1], NULL);
    H = strtof(argv[2], NULL);
  }

  printf("For a rectangle L = %8.4f and H = %8.4f\n", L, H);
  printf(" -- Perimeter = %8.4f\n", rectangle_perimeter(L, H));
  printf(" -- Area      = %8.4f\n", rectangle_area(L, H));

  printf("For a square c = %8.4f\n", L);
  printf(" -- Perimeter = %8.4f\n", square_perimeter(L));
  printf(" -- Area      = %8.4f\n", square_area(L));

  printf("For a circle r = %8.4f\n", L);
  printf(" -- Perimeter = %8.4f\n", circle_perimeter(L));
  printf(" -- Area      = %8.4f\n", circle_area(L));

  return 0;
}
