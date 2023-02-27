#include <stdio.h>

typedef long long ll;

ll find_int_sqrt(ll n) {
	ll x = 1;
	while (x * x <= n) {
		++x;
	}

	return --x;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int x, y;
		scanf("%d %d", &x, &y);

		ll dist = y - x;

		ll sqrt = find_int_sqrt(dist);
		ll retval = 2 * sqrt - 1;

		ll square1 = sqrt * sqrt;
		ll square2 = (sqrt + 1) * (sqrt + 1);

		if (dist > square1) {
			++retval;
		}
		if (dist >= (square2 + square1 + 1) / 2) {
			++retval;
		}

		printf("%lld\n", retval);
	}
	return 0;
}