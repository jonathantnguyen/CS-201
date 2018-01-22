CC=gcc
# flag all warnings. default optimization level.
CFLAGS=-Wall -Og
# set up for use in gdb
DFLAGS=-g
PROGS=typing_word_game.c

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) $(DFLAGS) $< -o $@

clean:
	rm -f $(PROGS) *.o ~* 
