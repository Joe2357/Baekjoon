#include <stdio.h>

#define MAX_IDX (200 + 1)
int dp[MAX_IDX][MAX_IDX];
int n, k;

const int mod = (int)(1e9);

int main() {
	scanf("%d %d", &n, &k);

	for (int i = 0; i < MAX_IDX; ++i) {
		dp[0][i] = 1;
		dp[i][1] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 2; j <= k; ++j) {
			for (int a = 0; a <= i; ++a) {
				dp[i][j] += dp[i - a][j - 1], dp[i][j] %= mod;
			}
		}
	}

	printf("%d", dp[n][k]);
	return 0;
}