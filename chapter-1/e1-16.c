#include <stdio.h>

#define MAXLINE 20

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
	int len; /* current line length */
	int max; /* maximum length seen so far */
	char line[MAXLINE]; /* current input line */
	char longest[MAXLINE]; /* longest line saved here */

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	// MAXLINE - 1 is needed here as the string needs to store another null terminator
	if (max > MAXLINE - 1)
		printf("Longest line with %d characters (Exceeded maximum allowed size of %d characters, partially printed) - %s",
		       max, MAXLINE, longest);
	else if (max > 0)
		printf("Longest line with %d characters - %s", max, longest);

	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	// i tracks the real line length and can exceed max
	// j inserts the characters in the array index, cannot exceed max
	int c, i, j;

	j = 0;

	// This loop now iterates through the entire line instead of stopping at the max
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		// Since the array needs to store an extra '\n' and '\0', the line length that can be stored cannot exceed limit - 2
		if (i < lim - 2) {
			s[j] = c;
			++j;
		}
	}
	// Reaches end of line, inserts the newline character and increments j and i
	if (c == '\n') {
		s[j] = c;
		++j;
		++i;
	}
	// Inserts a null terminater to represent a C-string
	s[j] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
