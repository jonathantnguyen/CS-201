CC=gcc
CFLAGS=
DFLAGS=
PROGS= fp_parse

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) $(DFLAGS) $< -o -g -Wall $@

clean:
	rm -f $(PROGS) *.o ~* 