#include <stdio.h>

typedef long long ll;

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
	ll a, b;
	scanf("%lld %lld", &a, &b);
	if (a > b) {
		ll temp = a;
		a = b, b = temp;
	}

	printf("%lld\n", max(0, b - a - 1));
	for (ll i = a + 1; i < b; ++i) {
		printf("%lld ", i);
	}

	return 0;
}