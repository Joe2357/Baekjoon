#include <stdio.h>

typedef long long ll;
const ll DIGIT = 10;
const ll SUM_ZERO_TO_NINE = 45;

#define min(a, b) (((a) > (b)) ? (b) : (a))

ll func(ll x) {
	ll ret = 0;

	for (ll std = 1; x >= std; std *= DIGIT) {
		ll quotient = x / (std * 10);
		ll d = (x / std) % DIGIT;
		ll remained = x % std;

		// prllf("q : %d, d : %d, r : %d\n", quotient, d, remained);

		ret += (SUM_ZERO_TO_NINE * quotient * std);
		ret += ((d * (d - 1)) / 2 * std);
		ret += (d * (remained + 1));
	}

	return ret;
}

ll main() {
	ll l, u;
	scanf("%lld %lld", &l, &u);

	// prllf("%lld %lld\n", func(u), func(l - 1));

	printf("%lld", func(u) - func(l - 1));
	return 0;
}