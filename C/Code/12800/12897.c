#include <stdio.h>

typedef long long ll;

const ll MOD = (ll)(1e9 + 7);

int main() {
	int n;
	scanf("%d", &n);

	ll ret = 1LL;
	for (int i = 0; i < n; ++i) {
		ret *= 3LL;
		ret %= MOD;
	}
	printf("%lld", ret - 1LL);
	return 0;
}