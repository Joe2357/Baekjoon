#include <stdio.h>

typedef long long ll;

#define MAX_IDX 30
#define MAX_COL 3

ll dp[MAX_IDX + 1][1 << MAX_COL];
int n;

void init() {
    dp[0][7] = 1LL;
	return;
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = dp[i - 1][7];
		dp[i][1] = dp[i - 1][6];
		dp[i][2] = dp[i - 1][5];
		dp[i][3] = dp[i - 1][4] + dp[i][0];
		dp[i][4] = dp[i - 1][3];
		dp[i][5] = dp[i - 1][2];
		dp[i][6] = dp[i - 1][1] + dp[i][0];
		dp[i][7] = dp[i][1] + dp[i][4];
		if (i > 1) {
			dp[i][7] += dp[i - 2][7];
		}
	}
	return;
}

int main() {
	init();
	scanf("%d", &n);

	solve();

	printf("%lld", dp[n][(1 << MAX_COL) - 1]);
	return 0;
}