#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		// LCM * GCD = a * b
		long long a, b;
		scanf("%lld %lld", &a, &b);
		long long LCM = a * b;
		// Euclidean algorithm
		while (b) {
			long long temp = a;
			a = b, b = temp % b;
		}
		LCM /= a;
		printf("%lld\n", LCM);
	}
	return 0;
}