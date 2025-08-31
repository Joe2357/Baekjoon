#include <stdio.h>

#define NUMBER_OF_WORDS 5
#define MAX_LEN 15

char input[NUMBER_OF_WORDS][MAX_LEN + 1];

int main() {
	for (int i = 0; i < NUMBER_OF_WORDS; ++i) {
		scanf("%s", input[i]);
	}
	for (int j = 0; j < MAX_LEN; ++j) {
		for (int i = 0; i < NUMBER_OF_WORDS; ++i) {
			if (input[i][j] != '\0') {
				printf("%c", input[i][j]);
			}
		}
	}
	return 0;
}