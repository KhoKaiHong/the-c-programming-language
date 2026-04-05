#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

// Counts lines, word and characters in an input

// Since any characters wrapped in whitespaces are defined as a word, to test this program
// edge cases such as empty inputs and multiple consecutive whitespaces should be included

// The programmer also needs to think of how he/she wants to define a word. Should
// words that contain numbers or multiple punctuations such as ab123 or h$h1n2*, be defined as a word,
// and what about forgotten spaces after punctuations such as hello,world or hello.World  

int main()
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;

	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n') {
			++nl;
		}
		if (c == '\n' || c == '\t' || c == ' ') {
			state = OUT;
		} else if (state == OUT) {
			state = IN;
			++nw;
		}
	}

	printf("\nSummary\n");
	printf("Number of characters: %d\n", nc);
	printf("Number of words: %d\n", nw);
	printf("Number of lines: %d\n", nl);
}
