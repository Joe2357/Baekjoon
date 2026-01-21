#include <stdio.h>

/*
N = 0인 경우 : 1가지
N = 1인 경우 : 1가지
N = 2인 경우 : 2가지 (2, 1->1)
N = 3인 경우 : 4가지 (3, 2->1, 1->2, 1->1->1)
N = 4인 경우 : 8가지
결국 N = k인 경우 가짓수는 2^{k-1}번 (예외 있음)
*/

typedef long long ll;

const ll MODULAR = (ll)(1e9 + 7);

// 입력의 범위가 크므로 분할정복 사용
ll power_modular(ll base, ll exponent, ll mod) {
	if (exponent < 1) {
		return 1;
	}

	ll ret = 1;
	base %= mod;
	while (exponent > 0) {
		if (exponent % 2 == 1) {
			ret = (ret * base) % mod;
		}
		base = (base * base) % mod;
		exponent = exponent / 2;
	}
	return ret;
}

ll main() {
	ll n;
	scanf("%lld", &n);
	printf("%lld", power_modular(2, (n - 1), MODULAR));
	return 0;
}