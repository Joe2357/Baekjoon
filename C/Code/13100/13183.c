#include <stdio.h>

typedef long long ll;
const ll MOD = (ll)(1e9 + 7);

int main() {
	ll h, w;
	scanf("%lld %lld", &h, &w);
	h %= MOD, w %= MOD;

	printf("%lld", (h + 2LL) * (w + 2LL) % MOD);
	return 0;
}