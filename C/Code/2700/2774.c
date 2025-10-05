#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define DIGIT 10

int solve(int x) {
	bool digit[DIGIT + 1] = {false};

	while (x > 0) {
		digit[x % DIGIT] = true;
		x /= DIGIT;
	}

	int ret = 0;
	for (int i = 0; i < DIGIT; ++i) {
		ret += (digit[i] == true);
	}
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int x;
		scanf("%d", &x);
		printf("%d\n", solve(x));
	}
	return 0;
}