#include <stdio.h>

int main() {
	long long n;
	scanf("%lld", &n);
	long long temp = (1LL << n) + 1;
	printf("%lld", temp * temp);
	return 0;
}