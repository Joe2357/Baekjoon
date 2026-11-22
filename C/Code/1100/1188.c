#include <stdio.h>

int n, m;

int gcd(int a, int b) {
	while (b > 0) {
		int x = a;
		a = b, b = x % b;
	}
	return a;
}

int main() {
	scanf("%d %d", &n, &m);

	n %= m;

	int result;
	if (n == 0) {
		result = 0;
	} else {
		result = (m / gcd(m, n) - 1) * gcd(m, n);
	}

	printf("%d", result);
	return 0;
}