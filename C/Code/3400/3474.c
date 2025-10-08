#include <stdio.h>

int main(t, n) {
	for (scanf("%d", &t); t; t--) {
		scanf("%d", &n);
		long long result = 0;
		for (int i = 5; i <= n; i *= 5)
			result += n / i;
		printf("%lld\n", result);
	}
	return 0;
}