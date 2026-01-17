#include <stdio.h>

typedef long long ll;

const int MAX_IDX = (int)(1e7);

int main() {
	ll n;
	scanf("%lld", &n);

	ll sum = 0LL, ans = 0LL;
	for (ll left = 0LL, right = 0LL; left <= n;) {
		if (sum == n) {
			ans += 1LL;
			sum -= left, left += 1LL;
			right += 1LL, sum += right;
		} else if (sum < n) {
			right += 1LL, sum += right;
		} else {
			sum -= left, left += 1LL;
		}
	}

	printf("%lld", ans);
	return 0;
}