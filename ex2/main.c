#include <stdio.h>

// Basic version
int is_leap_year(int year) {
  // First, check if divisible by 400, this is the strong rule
  if (year % 400 == 0) {
    return 1;
    // Then, check if divisible by 4 AND not divisible by 100
  } else if ((year % 4 == 0) && (year % 100 != 0)) {
    return 1;
  }
  // Otherwise, return zero.
  return 0;
}

int is_leap_year_adv(int year) {
  // More optimized version with Boolean algebra
  return !(year % 400) || (!(year % 4) && (year % 100));
}

int test_date(int day, int month, int year) {
  if (month < 1 || month > 12) {
    return 0;
  }

  if (year < 0) {
    return 0;
  }

  // Use an array of months to know the number of days
  const int monthtab[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  const int leap_year = is_leap_year(year);
  if (month == 2) {
    if (day < 1 || day > (monthtab[1] + leap_year)) {
      // February case
      return 0;
    }
  } else if (day < 1 || day > monthtab[month - 1]) {
    return 0;
  }
  
  return 1;
}

void print_date(int day, int month, int year) {
  if (!test_date(day, month, year)) {
    printf("Error: Invalid date.\n");
  } else {
    printf("%d-%d-%d\n", day, month, year);
  }
}

void next_day(int day, int month, int year, int new_day[3]) {
  // If the date is invalid, we don't waste time.
  if (!test_date(day, month, year)) {
    new_day[0] = -1;
    new_day[1] = -1;
    new_day[2] = -1;
    return;
  }

  // Same technique as for testing...
  const int monthtab[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  const int leap_year_add = (month == 2) * is_leap_year(year);

  // Just math! Don't forget that `true` -> `1` in C
  int next_day = day % (monthtab[month - 1] + leap_year_add) + 1;
  int next_month = month % 12 + (next_day == 1);

  new_day[2] = year + (next_month == 1);
  new_day[1] = next_month;
  new_day[0] = next_day;
}

int main() {
  // Test array
  const int yeartab[] = {2022, 1996, 1080, 3147};
  for (int i = 0; i < 4; i++) {
    // If lines 73 / 74 confuse you, look up 'C ternary operators'
    printf("%d leap year -> norm: %s | adv: %s.\n", yeartab[i],
           is_leap_year(yeartab[i]) ? "Yes" : "No",
           is_leap_year_adv(yeartab[i]) ? "Yes" : "No");
  }

  // clang-format off
  const int triplets[][3] = {
    {20, 10, 2023}, 
    {31, 4, 1998}, 
    {75, 100, -89},
    {29, 2, 1996}
  };

  for (int i = 0; i < 4; i++) {
    print_date(triplets[i][0], triplets[i][1], triplets[i][2]);
  }
  // clang-format on

  for (int i = 0; i < 4; i++) {
    int nj[3] = {0, 0, 0};
    next_day(triplets[i][0], triplets[i][1], triplets[i][2], nj);
    print_date(nj[0], nj[1], nj[2]);
  }

  return 0;
}
