//This small program is used to calculate the
//Lagrange Error Bound for the computation of
//D decimal digits of e. Specifically, it
//is used to solve the following inequality:
//ceil(1 + 10^12 * ln(10)) <= \sum_{k=1}^{n+1} floor(ln(k))
//Here, n is the number of terms in the Taylor
//series needed to have the first trillion
//digits be correct. This formula is derived
//from the Lagrange Error Bound.
//
//Ultimately, the program takes as an input
//the number of decimal digits to which we wish
//to calculate e, and it outputs the number of
//terms in the Taylor series needed.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

int main(int argc, char **argv)
{
	//We expect two arguments:
	//argv[0]: the program name;
	//argv[1]: the number of desired decimal digits
	if(argc != 2)
	{
		printf("usage: %s [# of digits]\n", argv[0]);
	}
	else
	{
		//We set the desired number of decimal digits.
		//Interpret argv[1] in base 10, and copy
		//it to D.
		mpz_t D;
		mpz_init_set_str(D, argv[1], 10);

		//We set this equal to the left side of our inequality
		double D_double = mpz_get_d(D);
		double A_double = ceil(1 + D_double * log(10.0));
		mpz_t A;
		mpz_init_set_d(A, A_double);

		//We instantiate a variable, which will hold the left
		//side of the inequality once the loop is finished.
		mpz_t sum;
		mpz_init(sum);

		//We declare these variables in order to show the
		//real-time status of the computation.
		float f;

		mpz_t counter;
		mpz_init_set_ui(counter, 1);
		//The loop will break when A < sum
		while(mpz_cmp(A, sum) >= 0)
		{
			double c = mpz_get_d(counter);
			//This takes care of the summatory
			mpz_add_ui(sum, sum, (unsigned long int) floor(log(c)));

			//Since the computation takes a long time,
			//we give real-time feedback for the user
			//every certain number of iterations.
			if(mpz_divisible_ui_p(counter, 100000000) != 0)
			{
				f = (float) c / 1.0e+09;
				gmp_printf("%f Billion : %Zd\n", f, sum);
			}

			//Increment the counter
			mpz_add_ui(counter, counter, 1);
		}

		//Finally, we print the solution.
		gmp_printf("For D = %Zd digits, we need n = %Zd terms\n", D, counter);
	}

	return 0;
}
