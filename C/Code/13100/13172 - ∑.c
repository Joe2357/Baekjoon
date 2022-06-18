#include <stdio.h>

typedef long long ll;

const ll MOD = (ll)(1e9 + 7);

ll power(ll x, ll r) {
	if (r == 0) {
		return 1;
	} else if (r == 1) {
		return x;
	} else {
		ll a = power(x, r >> 1);
		a *= a, a %= MOD;
		if (r & 1) {
			a *= x, a %= MOD;
		}
		return a;
	}
}

ll make(ll a, ll b) {
	return b * power(a, MOD - 2) % MOD;
}

int main() {
	int m;
	scanf("%d", &m);

	long long ret = 0;
	while (m--) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		ret += make(a, b), ret %= MOD;
	}

	printf("%lld", ret);
	return 0;
}