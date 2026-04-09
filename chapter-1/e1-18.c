#include <stdio.h>

#define MAXINPUTSIZE 101
#define MAXLINESIZE 50

int getline(char line[], int limit);
void append(char line[], char input[], int loc, int limit);

int main()
{
	char line[MAXLINESIZE]; /* Holds the entered line */
	char input[MAXINPUTSIZE]; /* Holds all the lines entered */
	int loc, len;
	loc = 0;
	len = 1;

	for (int i = 0; i < MAXINPUTSIZE; i++)
		input[i] = '\0';

	while (len > 0) {
		// Reset the line array
		for (int i = 0; i < MAXLINESIZE; i++)
			line[i] = '\0';

		// Performs getline
		len = getline(line, MAXLINESIZE);

		// Appends the line to input array only if the size is more then 1 (since 1 contains only a '\n' character)
		if (len > 1) {
			append(line, input, loc, MAXINPUTSIZE);
			loc += len;
		}
	}

	// If loc already exceeds the maximum input size - 2, checks if the final third character is '\n'
	// If not, sets the final second character to '\n' and increments loc by 1
	if (loc > MAXINPUTSIZE - 2) {
		loc = MAXINPUTSIZE - 2;
		if (input[loc - 1] != '\n') {
			input[loc] = '\n';
			loc++;
		}
	}

	printf("%s\nTotal length entered: %d", input, loc);

	return 0;
}

// Gets a line terminated by '\n'
int getline(char line[], int limit)
{
	int ch, len;
	len = 0;

	while ((ch = getchar()) != EOF && ch != '\n') {
		if (len < limit - 1) {
			line[len] = ch;
			len++;
		}
	}

	if (ch == '\n') {
		// Clears all trailing whitespaces
		while (len - 1 >= 0 &&
		       (line[len - 1] == ' ' || line[len - 1] == '\t')) {
			line[len - 1] = '\0';
			len--;
		}
		line[len] = ch;
		len++;
	}

	return len;
}

// Appends a line to a specified location in the input until limit - 2 to allow for final '\n' and '\0'
void append(char line[], char input[], int loc, int limit)
{
	for (int i = 0; loc < limit - 2 && (input[loc] = line[i]) != '\n'; i++)
		loc++;
}
