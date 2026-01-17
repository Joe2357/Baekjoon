#include <stdio.h>

#define MAX_IDX 10000

int dp[MAX_IDX + 1];
int n, k;

int main() {
	scanf("%d %d", &n, &k);
	dp[0] = 1;

	while (n--) {
		int coin;
		scanf("%d", &coin);
		for (int i = coin; i <= k; ++i) {
			dp[i] += dp[i - coin];
		}
	}
	printf("%d", dp[k]);
	return 0;
}