/*
 * This program returns the number n of terms
 * required in order to compute the first D
 * digits of e.
 *
 * We use the inequality
 * 1 + 10^12 * ln(10) < \sum_{k=0}^n ln(k)
 * and solve for n.
 */

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

		//We set GMP Float default precision to 256 bits
		//in order to counteract round-off errors.
		mpf_set_default_prec(256);

		//We set A equal to the left side of the inequality
		mpf_t A;
		mpf_init(A);

		//We instantiate sum, which will hold the left
		//side of the inequality once the loop is finished.
		mpf_t sum;
		mpf_init(sum);

		//We declare these variables in order to show the
		//real-time status of the computation.
		float f;

		mpz_t i;
		mpz_init_set_ui(i, 1);
		//The loop will break when A < sum
		while(mpz_cmp(A, sum) >= 0)
		{
			mpf_add(sum, sum,

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
