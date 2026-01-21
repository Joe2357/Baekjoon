#include <math.h>
#include <stdio.h>

typedef long long ll;

int main() {
	ll x, y;
	scanf("%lld %lld", &x, &y);

	ll n = 0LL;
	while (n * (n + 1LL) < 2LL * (x + y)) {
		n += 1LL;
	}

	if (n * (n + 1LL) != 2LL * (x + y)) {
		printf("-1");
	} else {
		ll ret = 0LL;
		while (x > 0LL) {
			if (n >= x) {
				ret += 1LL, x = 0LL;
			} else {
				ret += 1LL, x -= n;
				n -= 1LL;
			}
		}
		printf("%lld", ret);
	}
	return 0;
}