//This small program is used to calculate the
//Lagrange Error Bound for the computation of
//one trillion digits of e. Specifically, it
//is used to solve the following inequality:
//ceil(1 + 10^12 * ln(10)) <= \sum_{k=1}^{n+1} floor(ln(k))
//Here, n is the number of terms in the Taylor
//series needed to have the first trillion
//digits be correct.

#include <stdio.h>
#include <math.h>

int main()
{
	//We set this equal to the left side of our inequality
	unsigned long long int A = (unsigned long long int) ceil(1 + pow(10.0, 12.0) * log(10.0));

	//We instantiate a variable, which will hold the left
	//side of the inequality once the loop is finished.
	unsigned long long int sum = 0;

	//We declare these variables in order to show the
	//real-time status of the computation.
	float f;
	unsigned long long int n;

	//The loop will break when A <= sum
	for(unsigned long long int c = 1; A > sum; c++)
	{
		sum += floor(log(c)); //This takes care of the summatory

		//Since the computation takes a long time,
		//we give real-time feedback for the user
		//every certain number of iterations.
		if(c % 100000000 == 0)
		{
			f = (float) c / 1.0e+09;
			printf("%f Billion : %llu\n", f, sum);
		}

		//We update this variable so that, once the loop is done,
		//we can know the number of iterations transcurred.
		n = c;
	}

	//Finally, we print the solution.
	printf("n = %llu : sum = %llu\n", n, sum);

	return 0;
}
