//This program uses GMP Rationals to approximate e.

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("usage: %s [number of terms]\n", argv[0]);
	}
	else
	{
		unsigned long long int terms = atoi(argv[1]);

		mpq_t sum;
		mpq_init(sum);

		mpz_t factorial;
		mpz_init(factorial);

		mpq_t factorial_q;
		mpq_init(factorial_q);

		mpq_t factorial_inverse;
		mpq_init(factorial_inverse);

		mpf_t sum_float;
		mpf_init(sum_float);

		for(unsigned long long int c = 0; c <= terms; c++)
		{
			mpz_fac_ui(factorial, (unsigned long int) c);
			mpq_set_z(factorial_q, factorial);
			mpq_inv(factorial_inverse, factorial_q);
			mpq_add(sum, sum, factorial_inverse);
			mpf_set_q(sum_float, sum);

			gmp_printf("%llu terms : %FG\n", c, sum_float);
		}
	}
	
	return 0;
}
