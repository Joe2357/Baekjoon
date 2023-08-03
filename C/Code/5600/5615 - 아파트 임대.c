#include <stdio.h>

typedef unsigned long long ll;
typedef char bool;
const bool true = 1;
const bool false = 0;

ll base[3] = {2, 7, 61};
int base_len = 3;

ll power(ll x, ll y, ll m) {
	ll res = 1;
	x %= m;

	while (y > 0) {
		if (y % 2 == 1) {
			res = (res * x) % m;
		}

		y /= 2;
		x = (x * x) % m;
	}

	return res;
}

bool miller(ll n, ll a) {
	if (a % n == 0) {
		return true;
	}

	ll d = n - 1;
	while (true) {
		ll temp = power(a, d, n);
		if (temp == n - 1) {
			return true;
		}
		if (d % 2 == 1) {
			return (temp == 1 || temp == n - 1);
		}
		d /= 2;
	}
}

bool isPrime(ll x) {
	ll result = true;
	for (int i = 0; i < base_len; ++i) {
		result &= miller(x, base[i]);
	}
	return result;
}

int main() {
	int n;
	scanf("%d", &n);

	int result = 0;
	for (int i = 0; i < n; ++i) {
		ll x;
		scanf("%lld", &x);

		if (isPrime(2 * x + 1) == true) {
			++result;
		}
	}

	printf("%d", result);
	return 0;
}