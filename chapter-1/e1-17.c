#include <stdio.h>

// maximum line size
#define MAXLINE 21
// length threshold to cause a display
#define THRESHOLD 10

int getline(char line[], int limit);

int main()
{
	char line[MAXLINE];
	int length;

	while ((length = getline(line, MAXLINE)) > 0) {
		// if length of line provided exceeds threshold length (inclusive '\n', exclusive '\0'), print the line
		if (length > THRESHOLD) {
			printf("%3d - %s", length, line);
		}
	}
	
	return 0;
}

// getline implementation remains the same
int getline(char line[], int limit)
{
	int i, j, c;

	j = 0;

	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < limit - 2) {
			line[j] = c;
			++j;
		}
	}

	if (c == '\n') {
		line[j] = c;
		++j;
		++i;
	}

	line[j] = '\0';

	return i;
}
