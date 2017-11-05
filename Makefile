CC=gcc
objects = LagrangeErrorBound.o

LagrangeErrorBound: $(objects)
	$(CC) -lm -o LagrangeErrorBound $(objects)

LagrangeErrorBound.o:

.PHONY: clean
clean:
	rm LagrangeErrorBound $(objects) log
