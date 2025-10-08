#include <stdio.h>

typedef unsigned long long ull;

ull power(ull a, ull b, ull mod) {
	ull result = 1;
	ull base = a % mod;

	while (b > 0) {
		if (b % 2 == 1) {
			result = (result * base) % mod;
		}
		base = (base * base) % mod;
		b /= 2;
	}
	return result;
}

ull main() {
	ull a, b, c;
	scanf("%llu %llu %llu", &a, &b, &c);
	printf("%llu", power(a, b, c));
	return 0;
}