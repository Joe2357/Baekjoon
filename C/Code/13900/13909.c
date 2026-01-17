#include <stdio.h>

int main() {
	long long n;
	scanf("%lld", &n);

	int count = 0;
	for (long long i = 1LL; (long long)(i * i) <= n; ++i) {
		count += 1;
	}
	printf("%d", count);
	return 0;
}