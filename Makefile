CFLAGS = -std=c11
LDFLAGS =
OBJS = hottest.o

hottest: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f hottest $(OBJS)

.PHONY: clean
