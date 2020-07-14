#include <stdio.h>

int main() {
	long long a, b, temp;
	scanf("%lld %lld", &a, &b);			// max input = 2 ^ 63
	while (a % b)						// finding gcd(a, b)
		temp = a % b, a = b, b = temp;
	while (b--)							// b = gcd(a, b)
		printf("1");
	return 0;
}