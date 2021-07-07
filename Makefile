CFLAGS = -std=c11
LDFLAGS = -lsensors -lm
OBJS = hottest.o

hottest: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f hottest $(OBJS)

.PHONY: clean
