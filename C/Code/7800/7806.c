#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define SQRT_MAX 40000

int n, k;
int ret;

bool isNotPrime[SQRT_MAX + 1];
int primes[SQRT_MAX + 1];
int primeCount;

#define min(a, b) ((a) < (b) ? (a) : (b))

void prime_init() {
	isNotPrime[0] = isNotPrime[1] = true;
	primeCount = 0;

	for (int i = 2; i <= SQRT_MAX; ++i) {
		if (isNotPrime[i] == false) {
			primes[primeCount++] = i;
			for (int j = i * i; j <= SQRT_MAX; j += i) {
				isNotPrime[j] = true;
			}
		}
	}
	return;
}

int power(int a, int b) {
	int ret = 1;
	for (int i = 0; i < b; ++i) {
		ret *= a;
	}
	return ret;
}

int solve() {
	ret = 1;

	for (int i = 0; i < primeCount && primes[i] <= k; ++i) {
		int x = primes[i];
		int cnt1 = 0;
		while (k % x == 0) {
			k /= x;
			++cnt1;
		}

		if (cnt1 > 0) {
			int cnt2 = 0, j = x;
			while (j <= n) {
				cnt2 += (n / j);
				j *= x;
			}

			ret *= power(x, min(cnt1, cnt2));
		}
	}

	if (k > 1 && k <= n) {
		ret *= k;
	}

	return ret;
}

int main() {
	prime_init();
	while (scanf("%d %d", &n, &k) != EOF) {
		printf("%d\n", solve());
	}
	return 0;
}