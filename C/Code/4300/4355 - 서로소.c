#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

int solve(int x) {
	if (x == 1) {
		return 0;
	}

	int retval = 1;
	for (int i = 2; i * i <= x; ++i) {
		int cnt = 0;
		int pi = 1;

		while (x % i == 0) {
			++cnt;
			x /= i, pi *= i;
		}

		if (cnt > 0) {
			retval *= (pi - pi / i);
		}
	}

	if (x > 1) {
		retval *= (x - 1);
	}
	return retval;
}

int main() {
	while (true) {
		int n;
		scanf("%d", &n);

		if (n == 0) {
			break;
		}

		printf("%d\n", solve(n));
	}
	return 0;
}