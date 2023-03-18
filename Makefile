CFLAGS += -std=c11 -O3 -ffast-math
LDFLAGS += -lsensors -lm
OBJS = hottest.o

hottest: $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f hottest $(OBJS)

.PHONY: clean
