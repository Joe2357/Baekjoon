#include <stdio.h>

int main(n, p) {
	scanf("%d %d", &n, &p);
	long long result = 1;
	for (int i = 2; i <= n; i++)
		result = result * i % p;
	printf("%lld", result);
	return 0;
}