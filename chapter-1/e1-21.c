#include <stdio.h>

#define TAB_STOP 8

int main()
{
	int ch, col, nb, nt;

	col = 0;
	nb = 0;
	nt = 0;

	while ((ch = getchar()) != EOF) {
		if (ch == ' ') {
			if ((col & TAB_STOP - 1) != 0)
				nb++;
			else {
				nb = 0;
				nt++;
			}
			col++;
		} else {
			while (nt > 0) {
				putchar('\t');
				nt--;
			}

			if (ch == '\t')
				nb = 0;
			else {
				while (nb > 0) {
					putchar(' ');
					nb--;
				}
			}

			if (ch == '\n') {
				// Resets the column number if newline encountered
				putchar(ch);
				col = 0;
			} else if (ch == '\t') {
				putchar(ch);
				col += TAB_STOP - (col & TAB_STOP - 1);
			} else {
				putchar(ch);
				col++;
			}
		}
	}
	return 0;
}
