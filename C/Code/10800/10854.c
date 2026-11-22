#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef unsigned long long ll;

ll base[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
const int base_len = 12;

ll multiply_modular(ll a, ll k, ll n) {
	ll ret = 0;
	a %= n;

	while (k > 0) {
		if ((k & 1) > 0) {
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
		if ((k & 1) > 0) {
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
		} else if ((d & 1) > 0) {
			return (m == 1);
		}

		d >>= 1;
	}
}

bool isPrime(ll n) {
	for (int i = 0; i < base_len; ++i) {
		if (base[i] % n == 0) {
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

ll get_abs(ll x) {
	if (x < 0) {
		return -x;
	} else {
		return x;
	}
}

ll pollard_rho_prime(ll n) {
	if (isPrime(n) == true) {
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

	if (isPrime(g) == true) {
		return g;
	} else {
		return pollard_rho_prime(g);
	}
}

ll solve(ll n) {
	ll ret = 1;

	// 앞의 소수는 전처리로 빼주기
	for (int i = 0; i < base_len; ++i) {
		ll prime_factor = base[i];

		ll cnt = 0;
		if (n % base[i] == 0) {
			while (n % prime_factor == 0) {
				++cnt;
				n /= prime_factor;
			}

			ret *= (cnt + 1);
		}
	}

	while (n > 1) {
		ll prime_factor = pollard_rho_prime(n);

		ll cnt = 0;
		while (n % prime_factor == 0) {
			++cnt;
			n /= prime_factor;
		}

		ret *= (cnt + 1);
	}
	return ret;
}

int main() {
	srand(time(NULL));

	ll num;
	scanf("%llu", &num);
	printf("%llu", solve(num));
	return 0;
}