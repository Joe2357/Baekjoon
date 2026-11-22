#include <stdio.h>

#define ALL 2
#define OUT 1
#define IN 0

#define MAX_IDX 10001
int cost[2][MAX_IDX];
int n, w;

#define min(a, b) (((a) > (b)) ? (b) : (a))

int getResult() {
	int dp[MAX_IDX][3] = {0};
	// first case
	dp[1][IN] = 1, dp[1][OUT] = 1;
	if (cost[IN][1] + cost[OUT][1] <= w) {
		dp[1][ALL] = 1;
	} else {
		dp[1][ALL] = 2;
	}

	// use dp algorithm
	for (int i = 2; i <= n; ++i) {
		dp[i][IN] = dp[i - 1][ALL] + 1;
		if (cost[IN][i] + cost[IN][i - 1] <= w) {
			dp[i][IN] = min(dp[i][IN], dp[i - 1][OUT] + 1);
		}

		dp[i][OUT] = dp[i - 1][ALL] + 1;
		if (cost[OUT][i] + cost[OUT][i - 1] <= w) {
			dp[i][OUT] = min(dp[i][OUT], dp[i - 1][IN] + 1);
		}

		dp[i][ALL] = dp[i - 1][ALL] + 2;
		if (cost[IN][i] + cost[OUT][i] <= w) {
			dp[i][ALL] = min(dp[i][ALL], dp[i - 1][ALL] + 1);
		}
		if (cost[IN][i] + cost[IN][i - 1] <= w) {
			dp[i][ALL] = min(dp[i][ALL], dp[i - 1][OUT] + 2);
		}
		if (cost[OUT][i] + cost[OUT][i - 1] <= w) {
			dp[i][ALL] = min(dp[i][ALL], dp[i - 1][IN] + 2);
		}
		if (cost[IN][i] + cost[IN][i - 1] <= w && cost[OUT][i] + cost[OUT][i - 1] <= w) {
			dp[i][ALL] = min(dp[i][ALL], dp[i - 2][ALL] + 2);
		}
	}

	return dp[n][ALL];
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &n, &w);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &cost[IN][i]);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &cost[OUT][i]);
		}

		// first case : no merge
		int retval = getResult();
		if (n > 1) {
			// second case : IN merge
			if (cost[IN][1] + cost[IN][n] <= w) {
				int tempA = cost[IN][1], tempB = cost[IN][n];
				cost[IN][1] = cost[IN][n] = w;
				retval = min(retval, getResult() - 1);
				cost[IN][1] = tempA, cost[IN][n] = tempB;
			}

			// third case : OUT merge
			if (cost[OUT][1] + cost[OUT][n] <= w) {
				int tempA = cost[OUT][1], tempB = cost[OUT][n];
				cost[OUT][1] = cost[OUT][n] = w;
				retval = min(retval, getResult() - 1);
				cost[OUT][1] = tempA, cost[OUT][n] = tempB;
			}

			// last case : IN OUT merge
			if (cost[IN][1] + cost[IN][n] <= w && cost[OUT][1] + cost[OUT][n] <= w) {
				cost[IN][1] = cost[IN][n] = w;
				cost[OUT][1] = cost[OUT][n] = w;
				retval = min(retval, getResult() - 2);
			}
		}

		printf("%d\n", retval);
	}
	return 0;
}