#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	long long result = 1;

	for (int i = 1; i <= n; ++i) {
		result *= i;
	}

	printf("%lld", result);
	return 0;
}