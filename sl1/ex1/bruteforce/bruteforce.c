#include <error.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef max_jobs
#define max_jobs 50
#endif
#ifndef MINC
#define MINC 32
#endif
#ifndef MAXC
#define MAXC 127
#endif
#define SIZE (MAXC - MINC)
static char characters[SIZE + 1];

pid_t bruteforce(char *val) {
  pid_t pid = fork();

  if (pid < 0) {
    perror("fork");
    exit(1);
  } else if (pid == 0) {
	int fd = open("/dev/null", O_WRONLY, S_IRUSR);
	dup2(fd, STDOUT_FILENO);
    int res = execl("./pw_checker_naive", "./pw_checker_naive", val, (char *)NULL);

    perror("execl");
    exit(1);
  }
  return pid;
}

int main() {
  for (int c = MINC; c < MAXC + 1; c++) {
    characters[c - MINC] = (char)c;
  }

  int njobs = 0;
  static pid_t jobs[max_jobs];

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      for (int k = 0; k < SIZE; k++) {
        for (int l = 0; l < SIZE; l++) {
          for (int m = 0; m < SIZE; m++) {
            for (int n = 0; n < SIZE; n++) {
              for (int o = 0; o < SIZE; o++) {
                for (int p = 0; p < SIZE; p++) {
                  char arg[9] = {characters[i], characters[l], characters[o],
                                 characters[j], characters[m], characters[p],
                                 characters[k], characters[n], '\0'};

                  jobs[njobs++] = bruteforce(arg);
                  if (njobs >= max_jobs) {
                    while (njobs--) {
                      int res;
                      wait(&res);
                      if (res == 0) {
                        exit(0);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  exit(1);
}