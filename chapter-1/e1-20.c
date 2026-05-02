#include <stdio.h>

#define TAB_STOP 8

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
	// Eg col = 1, 8 - (1 % 8) = 7; col = 14, 8 - (14 % 8) = 2
	int spaces = tab_stop - (col % tab_stop);
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
	// Eg col = 1, 8 - (0001 & 1000 - 0001); 8 - (0001 & 0111); 8 - 0001; 8 - 1 = 7
	// Eg col = 14, 8 - (1110 & 1000 - 0001); 8 - (1110 & 0111); 8 - 0110; 8 - 6 = 2
	int spaces = tab_stop - (col & tab_stop - 1);
	for (int j = 0; j < spaces; j++) {
		putchar(' ');
		col++;
	}
	return col;
}
