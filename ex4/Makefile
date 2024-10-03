CC = gcc
CFLAGS = -O0 -ggdb -pipe -Wall -Wextra -Werror -Isources/gestion-fichiers -Isources/gestion-chaines
LDFLAGS =

EXENAME = file-trim

GLOBALSOURCES  = sources/gestion-chaines/gestion-chaines.c
GLOBALSOURCES += sources/gestion-fichiers/gestion-fichiers.c

GLOBALOBJECTS = $(subst .c,.o,$(GLOBALSOURCES))
BIN_DIR = bin

# Check if bin directory exists, if not, create it
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

all: $(BIN_DIR)/tests $(BIN_DIR)/$(EXENAME) | $(BIN_DIR)

$(BIN_DIR)/$(EXENAME): sources/main.o $(GLOBALOBJECTS) | $(BIN_DIR)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BIN_DIR)/tests: sources/tests.o $(GLOBALOBJECTS) | $(BIN_DIR)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clear clean
clean:
	@rm -fv $(GLOBALOBJECTS) sources/main.o sources/tests.o test_file_res.txt
clear: clean
	@rm -fv $(BIN_DIR)/$(EXENAME) $(BIN_DIR)/tests

check: all
	@echo -n "Running test executable... "
	@bin/tests > /dev/null
	@echo success.
	@echo -n "Running main test... "
	@bin/$(EXENAME) test_file.txt test_file_res.txt > /dev/null
	@diff test_file_res.txt expected.txt
	@echo success.