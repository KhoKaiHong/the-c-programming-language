#include <stdio.h>

#define MAXLINE 21

int getline(char line[], int limit);
void reverse(char line[], int len);

int main()
{
	char line[MAXLINE];
	int len;

	while ((len = getline(line, MAXLINE)) > 0) {
		reverse(line, len);
		printf("%s\n", line);
	}

	return 0;
}

int getline(char line[], int limit)
{
	int ch, len;

	for (len = 0; len < limit - 1 && (ch = getchar()) != EOF && ch != '\n';
	     len++)
		line[len] = ch;

	if (ch == '\n') {
		line[len] = ch;
		len++;
	}

	line[len] = '\0';

	return len;
}

void reverse(char line[], int len)
{
	// Reverse only if strring exceeds length of 1
	if (len > 1) {
		int start = 0;
		int end = len - 1;

		// Decrements end once more if string ends with a '\n'
		if (line[end] == '\n') {
			end--;
		}

		while (end > start) {
			// Perform a XOR swap
			line[start] = line[start] ^ line[end];
			line[end] = line[end] ^ line[start];
			line[start] = line[start] ^ line[end];
			// Decrements end in increments start
			end--;
			start++;
		}
	}
}
