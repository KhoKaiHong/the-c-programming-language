#include <stdio.h>

// A program to print a Celcius-Farenheit table from 0 to 300 F

int main()
{
	printf("Celcius to Farenheit Table\n\n");
	float celcius, fahr;
	float lower, upper, step;

	lower = 0; /* lower limit of temperature scale */
	upper = 300; /* upper limit  */
	step = 20; /* step size */

	celcius = lower;

	while (celcius <= upper) {
		fahr = celcius * (9.0 / 5.0) + 32;
		printf("%3.0f\t%6.1f\n", celcius, fahr);
		celcius = celcius + step;
	}
}
