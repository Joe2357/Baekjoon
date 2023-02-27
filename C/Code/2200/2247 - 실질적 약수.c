#include <stdio.h>

#define MOD (int)(1e6)

int main() {
	int retval = 0;
	int n;
	scanf("%d", &n);

	for (int i = 2; i < n; ++i) {
		retval += (((n / i) - 1) * i);
		retval %= MOD;
	}

	printf("%d", retval);
	return 0;
}