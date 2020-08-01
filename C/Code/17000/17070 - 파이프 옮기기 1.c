#include <stdio.h>
#define DEBUG 0

int grid[16][16], dp[16][16][4], n;

// Summary of dp
// dp[y][x][type] = number of cases of pipe in (x, y) rotated type
// 0 : cols 1 : rows 2 : diagonal 3 : sum of cases

int main() {
	// input
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &grid[i][j]);

	// first init
	for (int i = 1; i < n; i++) {
		if (grid[0][i])
			break;
		dp[0][i][0] = 1, dp[0][i][3] = 1;
	}
	// dynamic programming
	for (int y = 1; y < n; y++) {
		for (int x = 1; x < n; x++) {
			if (!grid[y][x]) {
				// type 0
				dp[y][x][0] += dp[y][x - 1][0],
					dp[y][x][0] += dp[y][x - 1][2];

				// type 1
				dp[y][x][1] += dp[y - 1][x][1],
					dp[y][x][1] += dp[y - 1][x][2];

				// type 2
				if (!grid[y - 1][x] && !grid[y][x - 1])
					dp[y][x][2] += dp[y - 1][x - 1][0] +
					dp[y - 1][x - 1][1] +
					dp[y - 1][x - 1][2];
				dp[y][x][3] = dp[y][x][0] +
					dp[y][x][1] +
					dp[y][x][2];
			}
		}
	}

	// Debug
	if (DEBUG) {
		printf("\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d.%d.%d.%d ",
					dp[i][j][0], dp[i][j][1],
					dp[i][j][2], dp[i][j][3]);
			}
			printf("\n");
		}
	}

	printf("%d", dp[--n][n][3]);
	return 0;
}