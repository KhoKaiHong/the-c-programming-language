#include <stdio.h>

// Count blanks, tabs, newlines and characters in input

int main()
{
	int num_blanks = 0; // Count of ' '
	int num_tabs = 0; // Count of '\t'
	int num_newlines = 0; // Count of '\n'
	int num_chars = 0; // Count of characters

	int c; //Character scanned

	while ((c = getchar()) != EOF) {
		switch (c) {
		case ' ':
			++num_blanks;
			break;
		case '\t':
			++num_tabs;
			break;
		case '\n':
			++num_newlines;
			break;
		default:
			break;
		}
		++num_chars;
	}

	printf("\nSummary\n");
	printf("Number of characters: %d\n", num_chars);
	printf("Number of blanks: %d\n", num_blanks);
	printf("Number of tabs: %d\n", num_tabs);
	printf("Number of newlines: %d\n", num_newlines);
}
