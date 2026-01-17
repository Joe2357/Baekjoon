#include <stdio.h>

typedef struct DPNode {
	int maxV, minV;
} DPNode;

#define MAX_ROW (int)(1e5)
#define MAX_COL 3
const int LEFT = 0, MIDDLE = 1, RIGHT = 2;

DPNode dp[MAX_ROW + 1][MAX_COL];
int n;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		dp[i][LEFT] = (DPNode){a + max(dp[i - 1][LEFT].maxV, dp[i - 1][MIDDLE].maxV),
							   a + min(dp[i - 1][LEFT].minV, dp[i - 1][MIDDLE].minV)};
		dp[i][MIDDLE] = (DPNode){b + max(max(dp[i - 1][LEFT].maxV, dp[i - 1][MIDDLE].maxV), dp[i - 1][RIGHT].maxV),
								 b + min(min(dp[i - 1][LEFT].minV, dp[i - 1][MIDDLE].minV), dp[i - 1][RIGHT].minV)};
		dp[i][RIGHT] = (DPNode){c + max(dp[i - 1][MIDDLE].maxV, dp[i - 1][RIGHT].maxV),
								c + min(dp[i - 1][MIDDLE].minV, dp[i - 1][RIGHT].minV)};
	}

	printf("%d %d",
		   max(max(dp[n][LEFT].maxV, dp[n][MIDDLE].maxV), dp[n][RIGHT].maxV),
		   min(min(dp[n][LEFT].minV, dp[n][MIDDLE].minV), dp[n][RIGHT].minV));
	return 0;
}