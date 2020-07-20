#include <stdio.h>
#define MOD 1000000000
#define MAX_INDEX 200

int dp[MAX_INDEX + 1][MAX_INDEX + 1];

int main() {
	// init
	int n, k;
	scanf("%d %d", &n, &k);

	// dp init
	for (int i = 0; i <= n; i++)
		dp[1][i] = 1; // only 1 way to make number i

	// dp
	for (int i = 2; i <= k; i++)
		// (i, j) = sum of [(i - a, j - 1) + a]
		for (int j = 0; j <= n; j++)
			for (int a = 0; a <= j; a++)
				dp[i][j] += dp[i - 1][a], dp[i][j] %= MOD;

	// print result
	printf("%d", dp[k][n]);
	return 0;
}