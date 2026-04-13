#include <stdio.h>

#define TAB_STOP 4

// Regular detab, works for tab stops of any number
int detab(int col, int tab_stop);
// More performant detab without using modulo operator, works for tab stops for 2^n size only
int detab_bitwise(int col, int tab_stop);

int main()
{
	int ch, col;
	// col tracks the current number of character entered
	col = 0;

	while ((ch = getchar()) != EOF) {
		if (ch == '\t') {
			col = detab_bitwise(col, TAB_STOP);
		} else if (ch == '\n') {
			// Resets the column number if newline encountered
			putchar(ch);
			col = 0;
		} else {
			putchar(ch);
			col++;
		}
	}
	return 0;
}

int detab(int col, int tab_stop)
{
	// Spaces represent the number of spaces required to reach the tab stop
	// Eg col = 1, 4 - (1 % 4) = 4; col = 14, 4 - (14 % 4) = 2
	int spaces = TAB_STOP - (col % TAB_STOP);
	for (int j = 0; j < spaces; j++) {
		putchar(' ');
		col++;
	}
	return col;
}

// This detab uses a binary trick to skip modulo operations but works for only col_width of 2^n sizes
int detab_bitwise(int col, int tab_stop)
{
	// Spaces represent the number of spaces required to reach the tab stop
	// Eg col = 1, 4 - (0001 & 0100 - 0001); 4 - (0001 & 0011); 4 - 0001; 4 - 1 = 3
	// Eg col = 14, 4 - (1110 & 0100 - 0001); 4 - (1110 & 0011); 4 - 0010; 4 - 2 = 2
	int spaces = TAB_STOP - (col & TAB_STOP - 1);
	for (int j = 0; j < spaces; j++) {
		putchar(' ');
		col++;
	}
	return col;
}
