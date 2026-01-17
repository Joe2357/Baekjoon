#include <stdio.h>

#define MAX_IDX (int)(1e4)
const int MOD = (int)(1e5);
const int DIGIT = 10;

int ret[MAX_IDX + 1];

void init() {
	ret[1] = 1;

	for (int i = 2; i <= MAX_IDX; ++i) {
		int temp = ret[i - 1] * i;
		while (temp % DIGIT == 0) {
			temp /= DIGIT;
		}
		ret[i] = temp % MOD;
	}

	return;
}

int main() {
	init();
	for (int n; scanf("%d", &n) != EOF;) {
		printf("%5d -> %d\n", n, ret[n] % DIGIT);
	}
	return 0;
}