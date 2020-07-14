#include <stdio.h>

int main() {
	long long a, b;
	scanf("%lld %lld", &a, &b);
	if (a > b) { // swap value
		long long temp = a;
		a = b, b = temp;
	}
	if (a == b) { // same value
		printf("0");
		return 0;
	}
	printf("%lld\n", b - a - 1);
	for (long long i = a + 1; i < b; i++)
		printf("%lld ", i);
	return 0;
}