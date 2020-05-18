#include <stdio.h>

int main(t, n, m) {
	for (scanf("%d", &t); t; t--) {
		scanf("%d %d", &n, &m);
		unsigned long long result = 1;
		if (m - n > n)						// minimize operating time
			n = m - n;
		for (int i = n + 1; i <= m; i++)	// m! / n!
			result *= i;
		for (int i = 2; i <= m - n; i++)	// (m - n)!
			result /= i;					// result = m! / (n! * (m - n)!)
		printf("%lld\n", result);			// result = nCr ( Combination )
	}
	return 0;
}