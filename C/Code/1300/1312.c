#include <stdbool.h>
#include <stdio.h>

typedef long long ll;

ll get_pow(ll base, ll cnt, ll mod) {
	ll ret = 1LL;

	while (cnt > 0) {
		if (cnt % 2 == 1) {
			ret = (ret * base) % mod;
		}
		cnt /= 2, base = (base * base) % mod;
	}

	return ret;
}

int main() {
	ll a, b, n;
	scanf("%lld %lld %lld", &a, &b, &n);

	ll ret = a * get_pow(10, n - 1, b);
	printf("%lld", (ret * 10 / b) % 10);
	return 0;
}