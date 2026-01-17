#include <stdio.h>

typedef long long ll;

ll n, m;

int main() {
	scanf("%lld %lld", &n, &m);
	ll ret = 1LL;

	for (ll i = 1LL; i <= n; ++i) {
		ret = (ret * i) % m;
	}
	printf("%lld", ret);
	return 0;
}