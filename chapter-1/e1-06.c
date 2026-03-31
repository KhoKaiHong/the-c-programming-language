#include <stdio.h>

// From manpages:
// getchar() is equivalent to fgetc(stdin)
// fgetc() reads the next character from stream and returns it as an unsigned char cast to an int, or EOF on end of file or error
//
// putchar(c) is equivalent to putc(c, stdout)
// putc() is equivalent to fputc() except that it may be implemented as a macro which evaluates stream more than once
// fputc() writes the character c, cast to an unsigned char, to stream

int main()
{
	int c;

	c = getchar() != EOF;
	putchar(c);

	while ((c = getchar()) != EOF) {
		putchar(c);
	}
}
