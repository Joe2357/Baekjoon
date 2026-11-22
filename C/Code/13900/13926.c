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

		if (m == 1) {
			return true;
		} else if ((d & 1) > 0) {
			return (m == n - 1);
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

/*
오일러 phi 함수 결과 반환
  - 입력값 : phi(n)를 계산할 수 n
  - 출력값 : phi(n)
*/
ll phi(ll n) {
	ll ret = n;

	// 앞의 소수는 전처리로 빼주기
	for (int i = 0; i < base_len; ++i) {
		ll prime_factor = base[i];

		// phi 값에 추가
		if (n % base[i] == 0) {
			ret /= prime_factor;
			ret *= (prime_factor - 1);

			while (n % prime_factor == 0) {
				n /= prime_factor;
			}
		}
	}

	while (n > 1) {
		ll prime_factor = pollard_rho_prime(n);

		// phi 값에 추가
		ret /= prime_factor;
		ret *= (prime_factor - 1);

		while (n % prime_factor == 0) {
			n /= prime_factor;
		}
	}
	return ret;
}

int main() {
	srand(time(NULL));

	ll num;
	scanf("%llu", &num);
	printf("%llu", phi(num));
	return 0;
}