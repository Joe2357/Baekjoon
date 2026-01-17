#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	long long ret = 1LL;
	for (int i = 2; i <= n; ++i) {
		ret *= i;
	}
	printf("%lld", ret);
	return 0;
}