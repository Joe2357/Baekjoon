#include <stdio.h>

#define MAX_IDX 1000
const int NUMBERS = 10;

int count[MAX_IDX + 1];

int main() {
	int average_of_numbers = 0;
	for (int i = 0; i < NUMBERS; i++) {
		int input;
		scanf("%d", &input);

		count[input] += 1;
		average_of_numbers += input;
	}

	int mode_index = 0;
	for (int i = MAX_IDX; i > 0; --i) {
		if (count[i] > count[mode_index]) {
			mode_index = i;
		}
	}
	printf("%d\n%d", average_of_numbers / NUMBERS, mode_index);
	return 0;
}