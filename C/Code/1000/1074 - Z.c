#include <stdio.h>

int main() {
	int n, r, c;
	scanf("%d %d %d", &n, &r, &c);
	int result = 0;

	for (; n > 0; --n) {
		int x = 0;

		if (r >= (1 << (n - 1))) {
			x += 2;
			r -= (1 << (n - 1));
		}
		if (c >= (1 << (n - 1))) {
			x += 1;
			c -= (1 << (n - 1));
		}

		result += (x * (1 << (2 * n - 2)));
	}

	printf("%d", result);
	return 0;
}