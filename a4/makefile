CC=gcc
CFLAGS=
DFLAGS=
PROGS= assignment4

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) $(DFLAGS) $< -lm -o $@

clean:
	rm -f $(PROGS) *.o ~* 