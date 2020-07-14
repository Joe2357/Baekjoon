#include <stdio.h>

int T(int n) {							// sum of 1 ~ n
	return n * (n + 1) / 2;
}

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int n, result = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)    // W(n) = sum( for i in range(1, n + 1) i * T(i + 1))
			result += i * T(i + 1);
		printf("%d\n", result);
	}
}