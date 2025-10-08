#include <stdio.h>

typedef long long ll;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ll n;
		scanf("%lld", &n);
		printf("%lld\n", n * n);
	}
	return 0;
}