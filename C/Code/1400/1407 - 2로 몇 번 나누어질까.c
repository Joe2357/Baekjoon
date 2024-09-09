#include <stdio.h>

typedef long long ll;

const int MAX_DIGIT = 60;

ll solve(ll x) {
	if (x == 0) {
		return 0;
	}

	ll ret = 0;
	ll cnt = 0;

	for (int i = MAX_DIGIT; i >= 0; --i) {
		ll std = ((ll)1 << i);
		ll candidate = (x / std) - cnt;
        
		ret += std * candidate;
		cnt += candidate;
	}

	return ret;
}

ll a, b;

int main() {
	scanf("%lld %lld", &a, &b);
	printf("%lld", solve(b) - solve(a - 1));
	return 0;
}