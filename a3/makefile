CC=gcc
CFLAGS=
DFLAGS=
PROGS= fp_parse

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) $(DFLAGS) $< -lm -o $@

clean:
	rm -f $(PROGS) *.o ~* 