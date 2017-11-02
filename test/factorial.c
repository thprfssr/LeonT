#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>


int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("usage: %s [natural number]\n", argv[0]);
	}
	else
	{
		mpz_t a;
		mpz_init(a);

		mpz_fac_ui(a, (unsigned long int) atoi(argv[1]));

		//mpz_out_str(stdout, 10, a);
		gmp_printf("%Zd\n", a);
	}

	return 0;
}
