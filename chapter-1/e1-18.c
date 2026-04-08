#include <stdio.h>

#define MAXINPUTSIZE 100
#define MAXLINESIZE 50

int getline(char line[], int limit);
void append(char line[], char input[], int loc, int limit);

int main()
{
	char line[MAXLINESIZE];
	char input[MAXINPUTSIZE];
	int loc, len;
	loc = 0;
	len = 1;

	for (int i = 0; i < MAXINPUTSIZE; i++)
		input[i] = '\0';

	while (len > 0) {
		for (int i = 0; i < MAXLINESIZE; i++)
			line[i] = '\0';

		len = getline(line, MAXLINESIZE);

		if (len > 1) {
			append(line, input, loc, MAXINPUTSIZE);
			loc += len;
		}
	}

	if (loc > MAXINPUTSIZE - 2) {
		loc = MAXINPUTSIZE - 2;
		input[loc] = '\n';
		loc++;
		input[loc] = '\0';
		loc++;
	} else {
		input[loc] = '\0';
		loc++;
	}

	printf("%s", input);

	return 0;
}

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

void append(char line[], char input[], int loc, int limit)
{
	for (int i = 0; (input[loc] = line[i]) != '\n' && loc < limit - 2; i++)
		loc++;
}
