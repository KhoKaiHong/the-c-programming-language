#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD_LEN 20 //  Accepts word lengths from 1 - 20+

int main()
{
	int c, state, curr_len;
	state = OUT;
	curr_len = 0;
	int word_lengths[MAX_WORD_LEN];

	for (int i = 0; i < MAX_WORD_LEN; i++)
		word_lengths[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				state = OUT;
				if (curr_len >= MAX_WORD_LEN)
					word_lengths[MAX_WORD_LEN - 1]++;
				else
					word_lengths[curr_len - 1]++;
				curr_len = 0;
			}
		} else {
			if (state == OUT) {
				state = IN;
			}
			curr_len++;
		}
	}

	int total = 0;
	printf("\nHistogram of length of words from 1 - 20+\n");
	for (int i = 0; i < MAX_WORD_LEN; i++) {
		if (i == MAX_WORD_LEN - 1)
			printf("Length %3d+ ", i + 1);
		else
			printf("Length %3d  ", i + 1);
		
		for (int j = 0; j < word_lengths[i]; j++)
			putchar(219);
		
		if (word_lengths[i] > 0)
			printf(" %d\n", word_lengths[i]);
		else
			printf("\n");
		
		total += word_lengths[i];
	}
	printf("\nTotal number of words: %d\n", total);
}
