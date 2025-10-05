#include <stdio.h>

const int DIGIT = 10;

int solve(int c, int k) {
	if (k == 0) {
		return c;
	}

	int bill = 1;
	for (int i = 0; i < k; ++i) {
		bill *= DIGIT;
	}

	int quotient = c / bill;
	int remainder = c % bill;

	// 반올림
	if (remainder >= (bill / 2)) {
		quotient += 1;
	}
	return quotient * bill;
}

int main() {
	int c, k;
	scanf("%d %d", &c, &k);
	printf("%d", solve(c, k));
	return 0;
}