CC     = gcc
CFLAGS = -Wall -Wextra -O2 -DNDEBUG -ggdb
# On MacOS, add: -L/opt/homebrew/lib -I/opt/homebrew/include

PRODUCTS = pw_checker_naive pw_checker libhack.so libpasswds.so
DBG_SBLS = $(patsubst %,%.dbg,$(PRODUCTS))
SOURCES  = pw_checker_naive.c pw_checker.c passwds.c hack.c

define gendbg =
@echo "-- Extracting Debug Symbols from $@ to $@.dbg before stripping..."
objcopy --only-keep-debug $@ $@.dbg
strip --strip-debug $@
objcopy --add-gnu-debuglink=$@.dbg $@
@echo "-- Done."
endef

all: archive.tar.gz archive_dbg.tar.gz archive_src.tar.gz

archive.tar.gz: $(PRODUCTS)
	tar -cvzf $@ $^

archive_dbg.tar.gz: $(DBG_SBLS)
	tar -cvzf $@ $^

archive_src.tar.gz: $(SOURCES)
	tar -cvzf $@ $^

pw_checker_naive pw_checker_naive.dbg &: pw_checker_naive.o
	$(CC) $(CFLAGS) -o $@ $<
	@$(gendbg)

pw_checker pw_checker.dbg &: pw_checker.o libpasswds.so
	$(CC) $(CFLAGS) $< -o $@ -Wl,-rpath,./ -L./ -lpasswds -lcrypto -lssl
	@$(gendbg)

lib%.so lib%.so.dbg &: %.c
	$(CC) $(CFLAGS) -shared -fPIC $< -o $@
	@$(gendbg)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean clear
clean:
	-rm -v pw_checker_naive.o pw_checker.o
clear: clean
	-rm -v $(PRODUCTS) $(DBG_SBLS)
	-rm -v archive.tar.gz archive_dbg.tar.gz
