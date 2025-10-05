#include <stdio.h>

typedef long long ll;

int main() {
	ll ret = 1LL;
	int n, p;
	scanf("%d %d", &n, &p);

	for (int i = 1; i <= n; ++i) {
		ret = (ret * i) % p;
	}
	printf("%lld", ret);
	return 0;
}