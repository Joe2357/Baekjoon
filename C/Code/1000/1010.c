#include <stdio.h>

typedef unsigned long long ull;

ull get_combination(int n, int m) {
	ull result = 1;
	if (m - n > n) {
		n = m - n;
	}
	for (int i = n + 1; i <= m; i++) {
		result *= i;
	}
	for (int i = 2; i <= m - n; i++) {
		result /= i;
	}
	return result;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%llu\n", get_combination(n, m));
	}
	return 0;
}