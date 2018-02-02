CC=gcc
CFLAGS=
DFLAGS=
PROGS= setBits showBits

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) $(DFLAGS) $< -lm -o $@

clean:
	rm -f $(PROGS) *.o ~* 