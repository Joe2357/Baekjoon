#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef long long ll;

bool isPrime(ll n) {
	for (ll i = 2LL; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

ll multiply_modular(ll a, ll b, ll modulus) {
	ll result = 0LL;
	a = a % modulus;
	while (b > 0) {
		if (b % 2LL == 1LL) {
			result = (result + a) % modulus;
		}
		b = b >> 1LL;
		a = (a + a) % modulus;
	}
	return result;
}

ll power_modular(ll base, ll exponent, ll modulus) {
	ll result = 1LL;
	base = base % modulus;
	while (exponent > 0) {
		if (exponent % 2LL == 1LL) {
			result = multiply_modular(result, base, modulus);
		}
		exponent = exponent >> 1LL;
		base = multiply_modular(base, base, modulus);
	}
	return result;
}

bool solve(ll p, ll a) {
	return (isPrime(p) == false) && (power_modular(a, p, p) == a);
}

int main() {
	while (true) {
		ll p, a;
		scanf("%lld %lld", &p, &a);
		if (p == 0 && a == 0) {
			break;
		}
		printf("%s\n", (solve(p, a) == true) ? "yes" : "no");
	}
	return 0;
}