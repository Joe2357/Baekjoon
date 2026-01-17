#include <stdio.h>

typedef long long ll;

#define MAX_IDX (int)(1e6)
const int ODD = 0, EVEN = 1;
const ll SELECT_SC = 2LL, NOT_SELECT_SC = 24LL;
const ll MOD = (ll)(1e9 + 7);

ll dp[MAX_IDX + 1][2];
int n;

void init() {
	dp[0][ODD] = 0;
	dp[0][EVEN] = 1;
	return;
}

void solve() {
	for (int i = 1; i <= n; i++) {
		dp[i][ODD] = (dp[i - 1][EVEN] * SELECT_SC + dp[i - 1][ODD] * NOT_SELECT_SC) % MOD;
		dp[i][EVEN] = (dp[i - 1][ODD] * SELECT_SC + dp[i - 1][EVEN] * NOT_SELECT_SC) % MOD;
	}
	return;
}

int main() {
	init();
	scanf("%d", &n);
	solve();
	printf("%lld", dp[n][EVEN]);
	return 0;
}