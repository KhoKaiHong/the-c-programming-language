#include <stdio.h>

int main()
{
	int c;
	int prev = EOF;

	while ((c = getchar()) != EOF) {
		// Only skip if BOTH current and previous are spaces
		if (!(c == ' ' && prev == ' ')) {
			putchar(c);
		}
		prev = c; // Update previous for the next loop
	}
}
