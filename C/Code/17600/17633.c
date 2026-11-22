#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef unsigned long long ll;

#define MAX_BASE 12
ll base[MAX_BASE] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 27, 31, 37};

bool is_square(ll n) {
	ll lo = 0, hi = (1ULL << 32); // (1<<32)^2 = 2^64
	while (lo < hi) {
		ll mid = (lo + hi + 1) >> 1;
		if (mid <= n / mid)
			lo = mid; // mid*mid <= n
		else
			hi = mid - 1;
	}

	if (lo * lo == n) {
		return true;
	} else {
		return false;
	}
}

ll multiply_modular(ll a, ll k, ll n) {
	ll ret = 0;
	a %= n;

	while (k > 0) {
		if (k % 2 == 1) {
			ret = (ret + a) % n;
		}

		a = (a << 1) % n;
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

ll get_abs(ll n) {
	if (n < 0) {
		return -n;
	} else {
		return n;
	}
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

ll get_gcd(ll a, ll b) {
	while (b > 0) {
		ll temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

ll pollard_rho_prime(ll n) {
	if (is_prime(n) == true) {
		return n;
	}

	ll x = rand() % (n - 2) + 2;
	ll y = x;
	ll c = rand() % 10 + 1;
	ll g = 1;

	while (g == 1) {
		x = (multiply_modular(x, x, n) + c) % n;
		y = (multiply_modular(y, y, n) + c) % n;
		y = (multiply_modular(y, y, n) + c) % n;
		g = get_gcd(get_abs(x - y), n);
	}

	if (g == n) {
		return pollard_rho_prime(g);
	} else {
		return g;
	}
}

bool check_fermat(ll n) {
	for (int i = 0; i < MAX_BASE; ++i) {
		int cnt = 0;
		while (n % base[i] == 0) {
			n /= base[i];
			++cnt;
		}

		if ((base[i] % 4 == 3) && (cnt % 2 == 1)) {
			return false;
		}
	}

	while (n > 1) {
		ll prime_factor = pollard_rho_prime(n);

		int cnt = 0;
		while (n % prime_factor == 0) {
			n /= prime_factor;
			++cnt;
		}

		if ((prime_factor % 4 == 3) && (cnt % 2 == 1)) {
			return false;
		}
	}

	return true;
}

int solve(ll n) {
	/* n이 제곱수 :: 1 */
	if (is_square(n) == true) {
		return 1;
	}

	/* 페르마의 두 제곱수 정리 :: 2 */
	if (check_fermat(n) == true) {
		return 2;
	}

	ll x = n;
	while (x % 4 == 0) {
		x >>= 2;
	}

	if (x % 8 != 7) { /* 르장드르 세제곱수 정리 :: 3 */
		return 3;
	} else { /* 라그랑주 네제곱수 정리 :: 4 */
		return 4;
	}
}

int main() {
	srand((unsigned int)NULL);

	ll n;
	scanf("%llu", &n);
	printf("%d", solve(n));
	return 0;
}