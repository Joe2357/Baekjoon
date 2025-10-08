#include <stdio.h>
#define min(a, b) (((a) > (b)) ? (b) : (a))

int dp[3][1001];
int color[3][1001];
int n;

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		int r, g, b;
		scanf("%d %d %d", &r, &g, &b);
		color[0][i + 1] = r, color[1][i + 1] = g, color[2][i + 1] = b;
	}

	/* dp initialize */
	dp[0][0] = 0, dp[1][0] = 0, dp[2][0] = 0;

	/* dp */
	for (int i = 1; i <= n; ++i) {
		dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + color[0][i];
		dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + color[1][i];
		dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + color[2][i];
	}

	/* get result */
	printf("%d", min(dp[0][n], min(dp[1][n], dp[2][n])));
}