#include <stdio.h>

#define MAX_INDEX 1000
int dp[MAX_INDEX + 1][MAX_INDEX + 1];

#define MOD 1000000003
int dc(int color, int used) {

	// exception
	if (dp[color][used] != -1)
		return dp[color][used];
	else if (color / used < 2)
		return 0;

	// dp line
	dp[color][used] = (dc(color - 2, used - 1) + dc(color - 1, used)) % MOD;

	return dp[color][used];
}

int main() {

	// init
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			dp[i][j] = -1;
		}
	}

	// exception
	if (n / k < 2) {
		printf("0");
		return 0;
	}

	// dp init
	for (int i = 0; i <= k; i++)
		dp[0][i] = 0;
	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;
	dp[1][1] = 1;
	for (int i = 1; i <= k; i++)
		dp[i * 2][i] = 2;

	// print result
	printf("%d", dc(n, k));

	return 0;
}