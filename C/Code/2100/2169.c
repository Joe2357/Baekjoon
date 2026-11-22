#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define INF -123456789
#define M 1001
#define DIR 3

bool visit[M][M + 1];
int dp[M][M][DIR];
int grid[M][M];
int dir[DIR][2] = {{1, 0}, {0, 1}, {0, -1}};
int n, m;

#define max(a, b) (((a) > (b)) ? (a) : (b))
int func(int x, int y, int d) {
	if (x == n - 1 && y == m - 1) {
		return grid[x][y];
	} else if (dp[x][y][d] != INF) {
		return dp[x][y][d];
	}

	int c = INF;
	for (int i = 0; i < DIR; ++i) {
		int a = x + dir[i][0], b = y + dir[i][1];
		if (a >= 0 && a < n && b >= 0 && b < m && !visit[a][b]) {
			visit[a][b] = true;
			c = max(c, func(a, b, i) + grid[x][y]);
			visit[a][b] = false;
		}
	}
	return dp[x][y][d] = c;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &grid[i][j]);
			for (int k = 0; k < DIR; ++k) {
				dp[i][j][k] = INF;
			}
		}
	}

	visit[0][0] = true;
	printf("%d", func(0, 0, 0));
}