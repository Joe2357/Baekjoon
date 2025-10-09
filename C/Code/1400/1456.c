#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef long long ll;
#define MAX_IDX (ll)(1e7)
const ll MAX_CUBEROOT = (ll)(1e6);

bool isNotPrime[MAX_IDX + 1 + 1];

void prime_init() {
	isNotPrime[0] = true;
	isNotPrime[1] = true;
	for (int i = 2; i <= MAX_IDX; ++i) {
		if (isNotPrime[i] == false) {
			for (int j = i * 2; j <= MAX_IDX; j += i) {
				isNotPrime[j] = true;
			}
		}
	}
	return;
}

int main() {
	prime_init();
	ll a, b;
	scanf("%lld %lld", &a, &b);

	ll ret = 0LL;

	// 3제곱이 가능한 수들에 대해서
	for (ll i = 0LL; i <= MAX_CUBEROOT; ++i) {
		if (isNotPrime[i] == false) {
			for (ll x = i * i; x <= b; x *= i) {
				if (a <= x && x <= b) {
					ret += 1;
				}
			}
		}
	}

	// 3제곱이 불가능한 수들에 대해서
	for (ll i = MAX_CUBEROOT + 1; i <= MAX_IDX; ++i) {
		if (isNotPrime[i] == false) {
			ll x = i * i;
			if (a <= x && x <= b) {
				ret += 1;
			}
		}
	}

	printf("%lld", ret);
	return 0;
}