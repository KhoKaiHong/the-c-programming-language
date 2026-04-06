#include <stdio.h>

#define ASCII_0 48
#define ASCII_9 57
#define ASCII_CA 65
#define ASCII_CZ 90
#define ASCII_SA 97
#define ASCII_SZ 122
#define TOTAL_NUM ASCII_9 - ASCII_0 + 1
#define TOTAL_C_ALPH ASCII_CZ - ASCII_CA + 1
#define TOTAL_S_ALPH ASCII_SZ - ASCII_SA + 1

struct char_freq {
	int num_freq[TOTAL_NUM];
	int c_alph_freq[TOTAL_C_ALPH];
	int s_alph_freq[TOTAL_S_ALPH];
	int other_freq;
};

int main()
{
	int c, total;

	struct char_freq char_freq;

	for (int i = 0; i < TOTAL_NUM; i++)
		char_freq.num_freq[i] = 0;

	for (int i = 0; i < TOTAL_C_ALPH; i++)
		char_freq.c_alph_freq[i] = 0;

	for (int i = 0; i < TOTAL_S_ALPH; i++)
		char_freq.s_alph_freq[i] = 0;

	char_freq.other_freq = 0;

	total = 0;

	while ((c = getchar()) != EOF) {
		if (c >= ASCII_0 && c <= ASCII_9)
			char_freq.num_freq[c - ASCII_0]++;
		else if (c >= ASCII_CA && c <= ASCII_CZ)
			char_freq.c_alph_freq[c - ASCII_CA]++;
		else if (c >= ASCII_SA && c <= ASCII_SZ)
			char_freq.s_alph_freq[c - ASCII_SA]++;
		else
			char_freq.other_freq++;
		total++;
	}

	printf("\nHistogram of character frequencies\n");
	for (int i = 0; i < TOTAL_NUM; i++) {
		printf("%5c ", ASCII_0 + i);

		for (int j = 0; j < char_freq.num_freq[i]; j++)
			putchar(219);

		if (char_freq.num_freq[i] > 0)
			printf(" %d\n", char_freq.num_freq[i]);
		else
			printf("\n");
	}

	for (int i = 0; i < TOTAL_C_ALPH; i++) {
		printf("%5c ", ASCII_CA + i);

		for (int j = 0; j < char_freq.c_alph_freq[i]; j++)
			putchar(219);

		if (char_freq.c_alph_freq[i] > 0)
			printf(" %d\n", char_freq.c_alph_freq[i]);
		else
			printf("\n");
	}

	for (int i = 0; i < TOTAL_S_ALPH; i++) {
		printf("%5c ", ASCII_SA + i);

		for (int j = 0; j < char_freq.s_alph_freq[i]; j++)
			putchar(219);

		if (char_freq.s_alph_freq[i] > 0)
			printf(" %d\n", char_freq.s_alph_freq[i]);
		else
			printf("\n");
	}

	printf("%5s ", "Other");
	for (int j = 0; j < char_freq.other_freq; j++)
		putchar(219);

	if (char_freq.other_freq > 0)
		printf(" %d\n", char_freq.other_freq);
	else
		printf("\n");

	printf("\nTotal number of characters: %d\n", total);
}
