EXE_FILE=dbg

SOURCECC= $(wildcard *.c)
OBJECTCC=$(SOURCECC:.c=.o)
CFLAGS+=-g -c -Wall
LDFLAGS=

all: $(SOURCECC) $(EXE_FILE)

$(EXE_FILE): $(OBJECTCC) 
	$(CC) $(OBJECTCC) -o $@ $(LDFLAGS)

.c.o:
	$(CC)  $(CFLAGS) $< -o $@

clean:
	rm -f *.o $(EXE_FILE)
