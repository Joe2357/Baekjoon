#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef unsigned long long ll;

#define MAX_BASE 12
ll base[MAX_BASE] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

ll multiply_modular(ll a, ll k, ll n) {
	ll ret = 0;
	a %= n;

	while (k > 0) {
		if (k % 2 == 1) {
			ret = (ret + a) % n;
		}

		a = (a + a) % n;
		k >>= 1;
	}
	return ret;
}

ll power_modular(ll a, ll k, ll n) {
	ll ret = 1;
	a %= n;

	while (k > 0) {
		if (k % 2 == 1) {
			ret = multiply_modular(ret, a, n);
		}

		a = multiply_modular(a, a, n);
		k >>= 1;
	}
	return ret;
}

bool miller_rabin(ll n, ll a) {
	ll d = n - 1;

	while (true) {
		ll m = power_modular(a, d, n);

		if (m == n - 1) {
			return true;
		} else if (d % 2 == 1) {
			return (m == 1);
		}

		d >>= 1;
	}
}

bool is_prime(ll n) {
	for (int i = 0; i < MAX_BASE; ++i) {
		if (n == base[i]) {
			return true;
		} else if (n % base[i] == 0) {
			return false;
		} else if (miller_rabin(n, base[i]) == false) {
			return false;
		}
	}
	return true;
}

bool solve(ll n) {
	if (is_prime(n) == true) {
		return true;
	} else if (n == 9) {
		return true;
	} else {
		return false;
	}
}

int main() {
	ll a, b;
	scanf("%llu %llu", &a, &b);

	/* 홀수 맞추기 */
	if (a % 2 == 0) {
		++a;
	}
	if (b % 2 == 0) {
		--b;
	}

	for (ll i = a; i <= b; i += 2) {
		if (solve(i) == true) {
			printf("%llu ", i);
		}
	}
	return 0;
}