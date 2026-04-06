#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float fahr_to_cel(int fahr);

int main()
{
	printf("Farenheit to Celcius Table from %d - %dF\n", LOWER, UPPER);
	for (int i = LOWER; i <= UPPER; i += STEP) {
		printf("%3d\t%6.1f\n", i, fahr_to_cel(i));
	}
}

float fahr_to_cel(int fahr)
{
	return (5.0 / 9.0) * (fahr - 32.0);
}
