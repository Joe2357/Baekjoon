#include <stdio.h>

#define min(a, b) (((a) > (b)) ? (b) : (a))

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

#define INF 987654321
#define MAX_IDX 10001
	int dp[MAX_IDX] = {0};
	for (int i = 1; i < MAX_IDX; ++i) {
		dp[i] = INF;
	}
	dp[0] = 0;

	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		for (int j = a; j <= k; ++j) {
			dp[j] = min(dp[j], dp[j - a] + 1);
		}
	}

	if (dp[k] == INF) {
		printf("-1");
	} else {
		printf("%d", dp[k]);
	}
	return 0;
}