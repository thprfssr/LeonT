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

		//We set the desired number of decimal digits.
		//Interpret argv[1] in base 10, and copy
		//it to D.
		//mpz_t D;
		//mpz_init_set_str(D, argv[1], 10);

		//We let A be the left side of the inequality.
		double A = ceil(1 + D * log(10));

		//We instantiate sum, which will hold the left
		//side of the inequality once the loop is finished.
		//We set it to round towards minus infinity in order
		//to force the program to add more terms.
		//mpfr_t sum;
		//mpfr_init_set_ui(sum, 0, GMP_RNDD);
		double sum = 0.0;
		double B = floor(sum);

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
			}

			//Increment the counter
			i++;
		}

		//Finally, we print the solution.
		printf("For D = %s digits, we need n = %llu terms.\n", argv[1], i);

		/*
		//mpz_t i;
		//mpz_init_set_ui(i, 1);
		//The loop will break when A < sum
		while(mpfr_cmp(A, sum) >= 0)
		{
			//We do acrobacies in order to take
			//care of the summatory.
			mpfr_t tmp;
			mpfr_init_set_z(tmp, i, GMP_RNDN);
			mpfr_t logarithm;
			mpfr_init(logarithm);
			mpfr_log(logarithm, tmp, GMP_RNDD);
			mpfr_add(sum, sum, logarithm, GMP_RNDD);
			mpfr_clear(tmp);
			mpfr_clear(logarithm);

			//Since the computation takes a long time,
			//we give real-time feedback for the user
			//every certain number of iterations.
			if(mpz_divisible_ui_p(i, 1000000) != 0)
			{
				double f = mpz_get_d(i) / 1.0e+09;

				double sum_d = mpfr_get_d(sum, GMP_RNDN);

				gmp_printf("%f Billion : %f\n", f, sum_d);
			}

			//Increment the counter
			mpz_add_ui(i, i, 1);
		}

		//Finally, we print the solution.
		gmp_printf("For D = %Zd digits, we need n = %Zd terms\n", D, i);
		*/
	}

	return 0;
}
