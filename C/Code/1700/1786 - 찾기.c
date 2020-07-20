#include <stdio.h>
#include <string.h>
#define MAX_INDEX 1000000

char origin[MAX_INDEX + 1],
target[MAX_INDEX + 1];
int prefix[MAX_INDEX],
found[MAX_INDEX],
top;

int main() {
	// init
	gets(origin);
	gets(target);

	// kmp prefix init
	for (int i = 0, j = 1; target[j];)
		if (target[i] == target[j]) // same character
			prefix[j++] = ++i;
		else {				// different character
			if (i != 0) // more possibility to get prefix
				i = prefix[i - 1];
			else // no more chance
				prefix[j++] = 0;
		}

	/*
	for (int i = 0; i < strlen(target); i++)
		printf("%d ", prefix[i]);
	printf("\n");
*/

// kmp search
	int olength = strlen(origin),
		tlength = strlen(target);
	for (int i = 0, j = 0; i < olength;) {
		// printf("%d %d\n", i, j);

		// search possibility
		while (origin[i] == target[j] && j < tlength)
			i++, j++; // move pointer to next pos

		// escape while, time to judge that tharget string is the substring of origin
		if (j == tlength) { // it is true
			found[top++] = i - j + 1;
			j = prefix[j - 1];
		}
		else { // it is not same
			if (j > 0)
				j = prefix[j - 1];
			else
				i++;
		}
	}

	// print result
	printf("%d\n", top);
	for (int i = 0; i < top; i++)
		printf("%d ", found[i]);

	return 0;
}