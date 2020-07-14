#include <stdio.h>

int main(n, k) {
	scanf("%d %d", &n, &k);
	long long result = 1;
	for (int i = 1; i <= n; i++) // * n!
		result *= i;
	for (int i = 1; i <= k; i++) // / k!
		result /= i;
	for (int i = 1; i <= n - k; i++) // / (n-k)!
		result /= i;
	printf("%lld", result);
	return 0;
}