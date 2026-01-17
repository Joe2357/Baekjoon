#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef long long ll;

bool isPrime(ll x) {
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

ll getNextPrime(ll n) {
	if (n <= 2) {
		return 2;
	} else {
		for (ll x = n + (n % 2 == 0); true; x += 2) {
			if (isPrime(x) == true) {
				return x;
			}
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ll n;
		scanf("%lld", &n);
		printf("%lld\n", getNextPrime(n));
	}
	return 0;
}