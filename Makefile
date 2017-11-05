CC=gcc
objects = LagrangeErrorBound.o factorial.o
targets = LagrangeErrorBound factorial

all: $(targets)
	make $(targets)

LagrangeErrorBound: $(objects)
	$(CC) -lm -o $@ LagrangeErrorBound.o

factorial: $(objects)
	$(CC) -lgmp -o $@ factorial.o

LagrangeErrorBound.o:
factorial.o:

.PHONY: clean
clean:
	rm LagrangeErrorBound $(objects) log factorial
