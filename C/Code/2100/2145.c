#include <stdio.h>

const int DIGIT = 10;
const int NONE = -1;

int step(int x) {
	if (x < DIGIT) {
		return x;
	}

	int ret = 0;
	while (x > 0) {
		ret += (x % DIGIT);
		x /= DIGIT;
	}
	return step(ret);
}

int main() {
	int n = NONE;
	for (; n > 0; scanf("%d", &n)) {
		int result = step(n);
		printf("%d\n", result);
	}
	return 0;
}