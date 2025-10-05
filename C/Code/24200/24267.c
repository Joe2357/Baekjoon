#include <stdio.h>

int main() {
	long long n;
	scanf("%lld", &n);

	long long ret = 0LL;
	for (long long i = 1LL; i <= n - 2; ++i) {
		ret += ((i * (i + 1)) / 2);
	}
	printf("%lld\n3", ret);
	return 0;
}