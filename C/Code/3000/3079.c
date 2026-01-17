#include <stdio.h>

typedef long long ll;

#define MAX_IDX (int)(1e5)
const ll MAX_ANS = (ll)(1e18);

ll judge_time[MAX_IDX];
int n;
ll m;

int main() {
	scanf("%d %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &judge_time[i]);
	}

	ll left = 1, right = MAX_ANS;
	while (left < right) {
		ll mid = (left + right) / 2;

		ll total = 0LL;
		for (int i = 0; i < n; i++) {
			total += (mid / judge_time[i]);
			if (total >= m) {
				break;
			}
		}
		if (total >= m) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	printf("%lld\n", left);
	return 0;
}