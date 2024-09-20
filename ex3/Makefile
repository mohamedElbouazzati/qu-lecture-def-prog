CC = gcc
CFLAGS := $(CFLAGS) -O2 -Wall -Werror -I.
LDFLAGS := $(LDFLAGS)

all: main

main: main.o geo_functions/geo_functions.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) -o $@ -c $^

geo_functions/geo_functions.o: geo_functions/geo_functions.c
	$(CC) $(CFLAGS) -o $@ -c $^

.PHONY: clean clear
clean:
	@rm -fv main.o geo_functions/geo_functions.o
clear: clean
	@rm -fv main
