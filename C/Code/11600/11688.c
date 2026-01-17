#include <stdio.h>

typedef long long ll;

ll gcd(ll a, ll b) {
	while (b > 0) {
		ll temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	ll a, b, l;
	scanf("%lld %lld %lld", &a, &b, &l);

	ll gcd_ab = gcd(a, b);
	ll lcm_ab = lcm(a, b);

	ll ret = 1;

	if (l % lcm_ab != 0) {
		ret = -1;
	} else {
		ll need = l / lcm_ab;

		ret = need;
		for (ll i = 2LL; i <= need; ++i) {
			if (need % i == 0) {
				while (need % i == 0) {
					need /= i;
				}

				// 공통인수 나누기
				while (a % i == 0 && b % i == 0) {
					a /= i;
					b /= i;
					ret *= i;
				}

				// a에만 있는 인수 나누기
				while (a % i == 0) {
					a /= i;
					ret *= i;
				}
				// b에만 있는 인수 나누기
				while (b % i == 0) {
					b /= i;
					ret *= i;
				}
			}
		}
	}

	printf("%lld", ret);
	return 0;
}