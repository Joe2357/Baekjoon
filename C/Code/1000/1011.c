#include <stdio.h>

typedef long long ll;

ll sqrt(ll n) {
	ll x;
	for (x = 1; x * x <= n; x += 1) {
	}
	return x - 1LL;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int x, y;
		scanf("%d %d", &x, &y);

		ll dist = y - x;

		ll sqrt_value = sqrt(dist);
		ll ret = 2 * sqrt_value - 1;

		ll square1 = sqrt_value * sqrt_value;
		ll square2 = (sqrt_value + 1) * (sqrt_value + 1);

		ret += (dist > square1);
		ret += (dist >= (square2 + square1 + 1) / 2);

		printf("%lld\n", ret);
	}
	return 0;
}