#include <stdio.h>

int main()
{
	// Compiler emits warning: unknown escape sequence: '\c', but still compiles.
	// Program will compile successfully, the escvape sequence is ignored and a 'c' is printed.
	printf("\c");
}
