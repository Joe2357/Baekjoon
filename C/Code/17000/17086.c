#include <stdio.h>

typedef int bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 50
const int INF = 987654321;
#define MAX_DIRECTION 8

int grid[MAX_IDX][MAX_IDX];
int ret[MAX_IDX][MAX_IDX];
int n, m;

typedef struct Position {
	int x, y;
} Position;

const Position directions[MAX_DIRECTION] = {
	{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

void read_input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &grid[i][j]);
			ret[i][j] = INF;
		}
	}
	return;
}

void dfs(Position pos, int depth) {
	if (ret[pos.x][pos.y] <= depth) {
		return;
	}
	ret[pos.x][pos.y] = depth;

	for (int i = 0; i < MAX_DIRECTION; ++i) {
		int new_x = pos.x + directions[i].x, new_y = pos.y + directions[i].y;

		if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m) {
			dfs((Position){new_x, new_y}, depth + 1);
		}
	}
	return;
}

void solve() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == true) {
				dfs((Position){i, j}, 0);
			}
		}
	}
	return;
}

int get_result() {
	int result = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			result = max(result, ret[i][j]);
		}
	}
	return result;
}

int main() {
	read_input();
	solve();
	printf("%d", get_result());
	return 0;
}