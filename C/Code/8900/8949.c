#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 7
const int DIGIT = 10;

int arr[2][MAX_IDX];

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	for (int i = 0; i < MAX_IDX; ++i) {
		arr[0][i] = a % DIGIT, a /= DIGIT;
		arr[1][i] = b % DIGIT, b /= DIGIT;
	}

	bool first_digit_appeared = false;
	for (int i = MAX_IDX - 1; i >= 0; --i) {
		int d = arr[0][i] + arr[1][i];

		if (d > 0 || first_digit_appeared == true) {
			printf("%d", d);
			first_digit_appeared = true;
		}
	}

	return 0;
}