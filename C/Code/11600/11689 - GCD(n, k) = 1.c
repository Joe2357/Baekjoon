#include <stdio.h>

typedef long long ll;

ll phi(ll x) {
	ll retval = 1;
	ll a = x;

	for (ll i = 2; i * i <= x; ++i) {
		if (i >= a) {
			break;
		}

		int divCount = 0;
		ll divRet = 1;
		while (a % i == 0) {
			++divCount, divRet *= i;
			a /= i;
		}

		if (divCount > 0) {
			divRet /= i;
			retval *= (divRet * (i - 1));
		}
	}
	if (a > 1) {
		retval *= (a - 1);
	}

	return retval;
}

int main() {
	ll n;
	scanf("%lld", &n);
	printf("%lld", phi(n));
	return 0;
}