#include <stdio.h>

int main()
{
	int c;
	int prev = EOF;

	while ((c = getchar()) != EOF) {
		// Only skip if both current and previous are spaces
		if (!(c == ' ' && prev == ' ')) {
			putchar(c);
		}
		// Update previous for the next loop
		prev = c; 
	}
}
