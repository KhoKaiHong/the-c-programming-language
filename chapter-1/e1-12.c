#include <stdio.h>

#define OUT 0
#define IN 1

int main()
{
	int c, state;
	state = OUT;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			// If whitespace encountered and state is IN, set state to OUT and put a newline
			if (state == IN) {
				putchar('\n');
				state = OUT;
			}
		} else if (state == OUT) {
			// Switches state to IN and puts character if currently in OUT state and non whitespace encountered
			state = IN;
			putchar(c);

		} else {
			// Puts character if currenty in IN state and non whitespace encountered
			putchar(c);
		}
	}
}
