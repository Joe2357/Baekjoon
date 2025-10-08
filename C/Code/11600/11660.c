#include <stdio.h>

#define MAX_IDX 1024 + 1

int dp[MAX_IDX][MAX_IDX];
int n, m;

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &dp[i][j]);
			dp[i][j] += (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]);
		}
	}

	while (m--) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		--a, --b;
		printf("%d\n", dp[c][d] - dp[c][b] - dp[a][d] + dp[a][b]);
	}

	return 0;
}