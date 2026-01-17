#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 4
const int TARGET_VALUE = 6174;
#define DIGIT 10

int step(int x) {
	int digits[DIGIT] = {0};
	for (int i = 0; i < MAX_LEN; ++i) {
		digits[x % DIGIT] += 1;
		x /= DIGIT;
	}

	int max_value = 0, min_value = 0;
	for (int i = DIGIT - 1; i >= 0; --i) {
		for (int j = 0; j < digits[i]; ++j) {
			max_value = max_value * DIGIT + i;
		}
	}
	for (int i = 0; i < DIGIT; ++i) {
		for (int j = 0; j < digits[i]; ++j) {
			min_value = min_value * DIGIT + i;
		}
	}
	return max_value - min_value;
}

int main() {
	int t;
	scanf("%d", &t);

	int ret;
	while (t--) {
		int n;
		scanf("%d", &n);

		for (ret = 0; n != TARGET_VALUE; ++ret) {
			n = step(n);
		}
		printf("%d\n", ret);
	}
	return 0;
}