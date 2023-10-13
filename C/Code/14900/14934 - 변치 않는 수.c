#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX (10000 * 2 + 10)

typedef struct Int {
	int digit[MAX_IDX];
} INT;

int n;
INT five, six;
bool isFiveBigger = false;

void init() {
	for (int i = 2; i < MAX_IDX; ++i) {
		five.digit[i] = 0, six.digit[i] = 0;
	}
	five.digit[0] = 5, five.digit[1] = 2, five.digit[2] = 6;
	six.digit[0] = 6, six.digit[1] = 7, six.digit[2] = 7, six.digit[3] = 5;
	return;
}

void solve(int x) {
	bool isFiveFound = false, isSixFound = false;

	// five
	for (int i = 1; i < 10; ++i) {
		if ((2 * five.digit[0] * i + five.digit[x]) % 10 == i) {
			isFiveFound = true;
			int temp;

			// 2bi update
			for (int j = 0; j < x; ++j) {
				five.digit[j + x] += (2 * five.digit[j] * i);
				temp = five.digit[j + x] / 10, five.digit[j + x] %= 10, five.digit[j + x + 1] += temp;
			}

			// i^2 update
			five.digit[x * 2] += ((i * i) % 10);
			temp = five.digit[x * 2] / 10, five.digit[x * 2] %= 10, five.digit[x * 2 + 1] += temp;
			five.digit[x * 2 + 1] += ((i * i) / 10);
			temp = five.digit[x * 2 + 1] / 10, five.digit[x * 2 + 1] %= 10, five.digit[x * 2 + 2] += temp;
		}

		if (isFiveFound == true) {
			break;
		}
	}
	if (isFiveFound == false) {
		five.digit[x] = 0;
	}

	// six
	for (int i = 1; i < 10; ++i) {
		if ((2 * six.digit[0] * i + six.digit[x]) % 10 == i) {
			isSixFound = true;
			int temp;

			// 2bi update
			for (int j = 0; j < x; ++j) {
				six.digit[j + x] += (2 * six.digit[j] * i);
				temp = six.digit[j + x] / 10, six.digit[j + x] %= 10, six.digit[j + x + 1] += temp;
			}

			// i^2 update
			six.digit[x * 2] += ((i * i) % 10);
			temp = six.digit[x * 2] / 10, six.digit[x * 2] %= 10, six.digit[x * 2 + 1] += temp;
			six.digit[x * 2 + 1] += ((i * i) / 10);
			temp = six.digit[x * 2 + 1] / 10, six.digit[x * 2 + 1] %= 10, six.digit[x * 2 + 2] += temp;
		}

		if (isSixFound == true) {
			break;
		}
	}
	if (isSixFound == false) {
		six.digit[x] = 0;
	}

	// compare
	if (five.digit[x] > six.digit[x]) {
		isFiveBigger = true;
	} else if (five.digit[x] < six.digit[x]) {
		isFiveBigger = false;
	}

	return;
}

int main() {
	init();

	scanf("%d", &n);
	for (int i = 2; i < n; ++i) {
		solve(i);
	}

	if (isFiveBigger == true) {
		printf("5");
	} else {
		printf("6");
	}
	return 0;
}