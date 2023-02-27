#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define SPACE 0
#define WALL 1

#define HORIZONTAL 0
#define VERTICAL 1
#define DIAGONAL 2

#define MAX_IDX 16
bool grid[MAX_IDX][MAX_IDX];
int dp[MAX_IDX][MAX_IDX][3];
int n;
int startX = 0, startY = 1;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int a;
			scanf("%d", &a);
			grid[i][j] = a;
		}
	}
	dp[startX][startY][HORIZONTAL] = 1;

	// first layer
	for (int i = 2; i < n; ++i) {
		if (grid[startX][i] == WALL) {
			break;
		}
		dp[startX][i][HORIZONTAL] = 1;	// only horizontal can fix
	}

	// other layer
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			if (grid[i][j] == SPACE) {
				dp[i][j][HORIZONTAL] = dp[i][j - 1][HORIZONTAL] + dp[i][j - 1][DIAGONAL];
				dp[i][j][VERTICAL] = dp[i - 1][j][VERTICAL] + dp[i - 1][j][DIAGONAL];
				if (grid[i - 1][j] == SPACE && grid[i][j - 1] == SPACE) {
					dp[i][j][DIAGONAL] = dp[i - 1][j - 1][HORIZONTAL] + dp[i - 1][j - 1][VERTICAL] + dp[i - 1][j - 1][DIAGONAL];
				}
			}
		}
	}

	printf("%d", dp[n - 1][n - 1][HORIZONTAL] + dp[n - 1][n - 1][VERTICAL] + dp[n - 1][n - 1][DIAGONAL]);
	return 0;
}