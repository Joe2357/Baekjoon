#include <stdio.h>

int main(n, k) {
	int dp[10001] = { 1 };					// case of making that value
	for (scanf("%d %d", &n, &k); n; n--) {
		int temp;							// coin's value
		scanf("%d", &temp);
		for (int j = temp; j <= k; j++)		// dynamic programming
			dp[j] += dp[j - temp];
	}
	printf("%d", dp[k]);					// case number that makes k
	return 0;
}