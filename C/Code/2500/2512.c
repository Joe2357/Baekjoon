#include <stdio.h>

typedef long long ll;

#define MAX_IDX 10000

ll demand[MAX_IDX];
int n;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
	ll left = 0LL, right = 0LL;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &demand[i]);
		right = max(right, demand[i]);
	}

	ll money;
	scanf("%lld", &money);
	ll ans = 0;

	while (left <= right) {
		ll mid = (left + right) / 2;
		ll total = 0LL;
		for (int i = 0; i < n; ++i) {
			total += min(demand[i], mid);
		}

		if (total <= money) {
			ans = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	printf("%lld", ans);
	return 0;
}