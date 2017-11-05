CC=gcc
objects = LagrangeErrorBound.o EulerRational.o factorial.o
targets = LagrangeErrorBound EulerRational factorial

all: $(targets)
	make $(targets)

LagrangeErrorBound: $(objects)
	$(CC) -lm -o $@ LagrangeErrorBound.o

EulerRational: $(objects)
	$(CC) -lgmp -o $@ EulerRational.o

factorial: $(objects)
	$(CC) -lgmp -o $@ factorial.o

LagrangeErrorBound.o:
EulerRational.o:
factorial.o:

.PHONY: clean
clean:
	rm LagrangeErrorBound $(objects) log EulerRational factorial
