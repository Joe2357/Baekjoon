#include <stdio.h>
#define max(a, b) ((a) > (b)) ? (a) : (b)
#define MAX_INDEX 500
#define True 1
#define False 0

typedef struct Position {
	int x, y;
} PS;

PS pos[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int grid[MAX_INDEX][MAX_INDEX],
dp[MAX_INDEX][MAX_INDEX],
n, result = -1;

int dfs(PS cur) {
	// if already visited
	if (dp[cur.x][cur.y] != -1)
		return dp[cur.x][cur.y];

	// get sum of 4 direction
	int retval = 0;
	for (int i = 0; i < 4; i++) {
		// make new position
		PS next = cur;
		next.x += pos[i].x, next.y += pos[i].y;

		// check whether it is valid position
		if (next.x >= 0 && next.x < n && next.y >= 0 && next.y < n)
			if (grid[next.x][next.y] > grid[cur.x][cur.y])
				retval = max(retval, dfs(next)); // get dp value
	}

	// update new value
	dp[cur.x][cur.y] = ++retval;
	result = max(result, retval);
	return retval;
}

int main() {
	// init
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &grid[i][j]);
			dp[i][j] = -1;
		}

	// DFS + dp
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) // if not visited, start DFS
			dfs((PS) { i, j });

	// print result
	printf("%d", result);
	return 0;
}