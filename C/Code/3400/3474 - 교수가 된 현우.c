#include <stdio.h>

int main(t, n) {
	for (scanf("%d", &t); t; t--) { // test case
		scanf("%d", &n);
		long long result = 0;   // '0' count = '5' count
		for (int i = 5; i <= n; i *= 5)
			result += n / i;
		printf("%lld\n", result);
	}
	return 0;
}