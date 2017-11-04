/*
 * This program returns the number n of terms
 * required in order to compute the first D
 * digits of e.
 *
 * We use the inequality
 * 1 + D * ln(10) < floor(\sum_{k=1}^n ln(k))
 * and solve for n.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
	//We expect two arguments:
	//argv[0]: the program name;
	//argv[1]: the number of desired decimal digits
	if(argc != 2)
	{
		printf("usage: %s [# of digits]\n", argv[0]);
	}
	else if(atoi(argv[1]) == 0)
	{
		printf("%s: must use positive integers!\n", argv[0]);
	}
	else
	{
		//We want to consider more digits than requested,
		//so we arbitrarily consider 32 more digits.
		double D = atof(argv[1]) + 32;

		//We let A be the left side of the inequality.
		double A = ceil(1 + D * log(10));

		//We instantiate sum, which will hold the left
		//side of the inequality once the loop is finished.
		double sum = 0.0;
		double B = floor(sum);

		//Open log file, and disable buffering
		//so thatit writes directly to the file instead
		//of to a buffer. Had we used a buffer, we would
		//have had to wait for the program to end.
		FILE *logfile;
		logfile = fopen("log", "w");
		setbuf(logfile, NULL);

		//The loop will break when A < B.
		unsigned long long int i = 1;
		while(A >= B)
		{
			sum += log((double) i);
			B = floor(sum);

			//We want to give live feedback to the user, since
			//the computation will take a while.
			if(i % 100000000 == 0)
			{
				double f = (double) i / 1.0e+9;
				printf("n = %f Billion \t sum = %f\n", f, sum);
				fprintf(logfile, "n = %f Billion \t sum = %f\n", f, sum);
			}

			//Increment the counter
			i++;
		}

		//Finally, we print the solution.
		printf("For D = %s digits, we need n = %llu terms.\n", argv[1], i);
		fprintf(logfile, "For D = %s digits, we need n = %llu terms.\n", argv[1], i);

		//Close the log file
		fclose(logfile);
	}

	return 0;
}
