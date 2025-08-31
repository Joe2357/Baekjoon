#include <stdio.h>

const int DIGIT = 10;
const int ZERO = 0;

int count_zero(int x) {
	if (x == ZERO) {
		return 1;
	}

	int ret = 0;
	while (x > 0) {
		if (x % DIGIT == ZERO) {
			ret += 1;
		}
		x /= DIGIT;
	}
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);

		int ret = 0;
		for (int i = n; i <= m; ++i) {
			ret += count_zero(i);
		}
		printf("%d\n", ret);
	}
	return 0;
}