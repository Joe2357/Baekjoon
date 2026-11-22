#include <stdio.h>

int n, k;
long long mod, digit_mod;

long long getDigit(int x) {
	long long r = 1;

	while (x > 0) {
		x /= 10, r *= 10;
	}
	return r;
}

int main() {
	scanf("%d %d", &n, &k);
	mod = n % k, digit_mod = getDigit(n) % k;

	int cur = mod;
	int result;
	for (result = 1; result <= k; ++result) {
		if (cur == 0) {
			break;
		} else {
			cur = (cur * digit_mod + mod) % k;
		}
	}

	if (result > k) {
		printf("-1");
	} else {
		printf("%d", result);
	}
	return 0;
}