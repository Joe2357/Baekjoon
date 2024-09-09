#include <stdio.h>

#define MAX_IDX 1000

char grid[MAX_IDX][MAX_IDX + 1];
int dp[MAX_IDX][MAX_IDX];
int n, m;

int result;

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define max(a, b) (((a) < (b)) ? (b) : (a))

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", grid[i]);
		for (int j = 0; j < m; ++j) {
			result = max(result, (grid[i][j] == '1'));
		}
	}

	for (int i = 0; i < m; ++i) {
		dp[0][i] = (grid[0][i] == '1');
	}
	for (int i = 0; i < n; ++i) {
		dp[i][0] = (grid[i][0] == '1');
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (grid[i][j] == '1') {
				dp[i][j] =
					min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
				result = max(result, dp[i][j]);
			}
		}
	}

	printf("%d", result * result);
	return 0;
}