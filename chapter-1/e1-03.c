#include <stdio.h>

// A program to print a Farenheit-Celcius table from 0 to 300 F

int main()
{
	printf("Farenheit to Celcius Table\n\n");
	float fahr, celcius;
	float lower, upper, step;

	lower = 0; /* lower limit of temperature scale */
	upper = 300; /* upper limit  */
	step = 20; /* step size */

	fahr = lower;

	while (fahr <= upper) {
		celcius = (5.0 / 9.0) * (fahr - 32);
		printf("%3.0f\t%6.1f\n", fahr, celcius);
		fahr = fahr + step;
	}
}
