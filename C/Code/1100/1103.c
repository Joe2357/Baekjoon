#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Position {
	int x, y;
} Position;

#define MAX_SIZE 50
const int INF = 987654321;
const int NONE = 0;
const char HOLE = 'H';

char grid[MAX_SIZE][MAX_SIZE + 1];
int dp[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE + 1];
int n, m;

#define MAX_DIR 4
const Position directions[MAX_DIR] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

#define max(a, b) ((a) > (b) ? (a) : (b))

void read_input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", grid[i]);
	}
	return;
}

bool isInGrid(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < m);
}

int dfs(Position pos) {
	if (dp[pos.x][pos.y] != NONE) {
		return dp[pos.x][pos.y];
	}

	int max_moves = 0;
	int step = grid[pos.x][pos.y] - '0';

	for (int i = 0; i < MAX_DIR; ++i) {
		Position next = {pos.x + directions[i].x * step, pos.y + directions[i].y * step};
		if (isInGrid(next.x, next.y) == true && grid[next.x][next.y] != HOLE) {
			if (visit[next.x][next.y] == true) {
				return dp[pos.x][pos.y] = INF;
			}

			visit[next.x][next.y] = true;
			int result = dfs(next);
			visit[next.x][next.y] = false;
			max_moves = max(max_moves, result);
		} else {
			max_moves = max(max_moves, 0);
		}
	}
	return dp[pos.x][pos.y] = max_moves + 1;
}

void solve() {
	visit[0][0] = true;
	dp[0][0] = dfs((Position){0, 0});
	return;
}

int main() {
	read_input();
	solve();
	printf("%d", (dp[0][0] >= INF ? -1 : dp[0][0]));
	return 0;
}