#include <stdio.h>

const int DIGIT = 10;

int main() {
	int n;
	scanf("%d", &n);

	for (int cur = 1, base = DIGIT; n > base; cur *= DIGIT, base *= DIGIT) {
		int quotient = n / base, remainder = n % base;
		n = quotient * base;
		if (remainder >= (base / 2)) {
			n += base;
		}
	}
	printf("%d", n);
	return 0;
}