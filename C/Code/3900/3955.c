#include <stdio.h>

typedef long long ll;

#define MAX_CNT (ll)(1e9)

void EEA(ll a, ll b) {
	ll r1 = a, r2 = b, s1 = 1, s2 = 0, t1 = 0, t2 = 1;
	ll r, s, t, q;

	while (r2 != 0) {
		q = r1 / r2;

		r = r1 % r2;
		r1 = r2, r2 = r;

		s = s1 - q * s2;
		s1 = s2, s2 = s;

		t = t1 - q * t2;
		t1 = t2, t2 = t;
	}
	s = s1, t = t1;

	if (r1 != 1) {
		printf("IMPOSSIBLE\n");
	} else {
		if (s >= 0) {
			t += a;
		}

#define STD (ll)(1e9)
		if (t > STD) {
			printf("IMPOSSIBLE\n");
		} else {
			printf("%lld\n", t);
		}
	}

	return;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		EEA(a, b);
	}
	return 0;
}