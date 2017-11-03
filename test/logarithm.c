#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	double logarithm = log((double) n);
	printf("log(%d) = %f\n", n, logarithm);

	return 0;
}
