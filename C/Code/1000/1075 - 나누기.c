#include <stdio.h>

int main(f) {
	long long n;					// max = 2,000,000,000
	scanf("%lld %d", &n, &f);
	n = n / 100 * 100;				// if n = 1234, n will be 1200
	for (int i = 0; i <= f; i++) {
		if (!((n + i) % f)) {
			if (!(i / 10))			// if target i < 10
				printf("0%d", i);
			else
				printf("%d", i);
			return 0;
		}
	}
	return 0;
}