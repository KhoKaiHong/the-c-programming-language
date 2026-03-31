#include <stdio.h>

// A program to print a Farenheit-Celcius Table from 300 to 0 F, using for loop

// These are known as macros, where the preprocessor will use them to manipulate the source code before compile time
#define LOWER 0
#define UPPER 300
#define STEP 20

// You can also use macros like this, but it is not recommended and a function is encouraged
#define CONVERT_F_TO_C(a) (5.0 / 9.0) * (a - 32)

int main()
{
	// This does not use macros
	printf("Farenheit to Celcius Table\n\n");
	for (int fahr = 300; fahr >= 0; fahr = fahr - 20) {
		printf("%3d\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
	}

	// This uses macros and the preprocessor will transform the code below to the one above before compile time
	printf("\nFarenheit to Celcius Table\n\n");
	for (int fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
		printf("%3d\t%6.1f\n", fahr, CONVERT_F_TO_C(fahr));
	}
}
