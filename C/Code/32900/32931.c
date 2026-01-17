#include <stdio.h>

typedef long long ll;

#define MAX_IDX (int)(2e5)
const ll INF = 987654321987654321;

/*
  dp[0][i]: i열 위 선택, 아래 선택 안함
  dp[1][i]: i열 아래 선택, 위 선택 안함
  dp[2][i]: i열 모두 선택
*/
ll grid[2][MAX_IDX + 1];
ll dp[3][MAX_IDX + 1];
int n;

#define max(a, b) ((a) > (b) ? (a) : (b))

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%lld", &grid[i][j]);
		}
	}
	return;
}

int main() {
	read_input();

	dp[0][1] = grid[0][1], dp[1][1] = -INF, dp[2][1] = grid[0][1] + grid[1][1];
	for (int i = 2; i <= n; ++i) {
		dp[0][i] = max(dp[0][i - 1], dp[2][i - 1]) + grid[0][i];
		dp[1][i] = max(dp[1][i - 1], dp[2][i - 1]) + grid[1][i];
		dp[2][i] = max(max(dp[0][i - 1], dp[1][i - 1]), dp[2][i - 1]) + grid[0][i] + grid[1][i];
	}

	printf("%lld", max(dp[1][n], dp[2][n]));
	return 0;
}