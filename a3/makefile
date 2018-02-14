CC=gcc
CFLAGS=
DFLAGS=
PROGS= fp_parse

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) $(DFLAGS) $< -o -g $@

clean:
	rm -f $(PROGS) *.o ~* 