#include <stdio.h>
#define MAX_INDEX 500
#define True 1
#define False 0

typedef char boolean;
typedef struct Position {
	int x, y;
} PS;

PS pos[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int grid[MAX_INDEX][MAX_INDEX],
dp[MAX_INDEX][MAX_INDEX],
n, m;

int dfs(PS cur) {
	// if already visited
	if (dp[cur.x][cur.y] != -1)
		return dp[cur.x][cur.y];

	// get sum of 4 distance
	int retval = 0;
	for (int i = 0; i < 4; i++) {
		// make new position
		PS next = cur;
		next.x += pos[i].x, next.y += pos[i].y;

		// check whether it is valid position
		if (next.x >= 0 && next.y >= 0 && next.x < n && next.y < m)
			if (grid[cur.x][cur.y] > grid[next.x][next.y])
				retval += dfs(next);
	}

	// get result
	dp[cur.x][cur.y] = retval;
	return retval;
}

int main() {
	// init
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &grid[i][j]);
			dp[i][j] = -1;
		}
	dp[n - 1][m - 1] = 1;

	// dp + DFS
	dfs((PS) { 0, 0 });
	printf("%d", dp[0][0]);
	return 0;
}