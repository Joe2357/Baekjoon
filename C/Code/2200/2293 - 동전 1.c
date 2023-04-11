#include <stdio.h>

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

#define MAX_IDX 10001
	int dp[MAX_IDX] = {0};
	dp[0] = 1;

	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		for (int j = a; j <= k; ++j) {
			dp[j] += dp[j - a];
		}
	}

	printf("%d", dp[k]);
	return 0;
}