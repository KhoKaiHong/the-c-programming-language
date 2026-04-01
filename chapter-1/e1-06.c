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

	putchar(72); // H
	putchar(101); // e
	putchar(108); // l
	putchar(108); // l
	putchar(111); // o

	putchar(13); // Carriage return
	putchar(10); // Line feed

	// Gets a character, due to precedence of operations, performs an equality check using != operation with EOF, then prints the output
	// 1 will be printed if getchar does not receive EOF, else 0 will be printed
	// To send an EOF signal, use Ctrl + Z in Windows, and Ctrl + D in Mac/Linux
	c = getchar() != EOF;
	printf("%d\n", c);

	while ((c = getchar()) != EOF) {
		putchar(c);
	}
}
