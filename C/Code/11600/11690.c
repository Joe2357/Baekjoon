#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef unsigned long long ull;

#define MAX_IDX (ull)(1e8)
const ull MOD = (ull)(1ULL << 32);

bool isNotPrime[MAX_IDX + 1];
ull n;

void init() {
	isNotPrime[0] = isNotPrime[1] = true;
	return;
}

int main() {
	init();
	scanf("%llu", &n);

	ull ret = 1ULL;
	for (ull i = 2ULL; i <= n; ++i) {
		if (isNotPrime[i] == false) {
			ull cur = i;
			while (cur <= n / i) {
				cur *= i;
			}
			cur %= MOD;
			ret = (ret * cur) % MOD;

			for (ull j = i * i; j <= MAX_IDX; j += i) {
				isNotPrime[j] = true;
			}
		}
	}

	printf("%llu", ret % MOD);
	return 0;
}