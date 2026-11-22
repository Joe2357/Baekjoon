#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Position {
	int x, y;
} Position;

#define MAX_IDX 100
const char EMPTY = '0', WALL = '1';
const int NONE = -1;

char grid[MAX_IDX][MAX_IDX + 1];
bool visited[MAX_IDX][MAX_IDX + 1];
int n, m;

#define MAX_DIR 4
const Position directions[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
Position queue[MAX_IDX * MAX_IDX];
int front, rear;

int ret;

void read_input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%s", grid[i]);
	}
	return;
}

void dfs(Position pos, int wall_count) {
	int x = pos.x, y = pos.y;
	if (x == m - 1 && y == n - 1) {
		ret = wall_count;
		return;
	}

	for (int i = 0; i < MAX_DIR; ++i) {
		int nx = x + directions[i].x, ny = y + directions[i].y;
		if (0 <= nx && nx < m && 0 <= ny && ny < n && visited[nx][ny] == false) {
			visited[nx][ny] = true;

			if (grid[nx][ny] == EMPTY) {
				dfs((Position){nx, ny}, wall_count);
			} else {
				queue[rear++] = (Position){nx, ny};
			}
		}
	}
	return;
}

void init() {
	ret = NONE;
	front = rear = 0;
	visited[0][0] = true;
	dfs((Position){0, 0}, 0);
	return;
}

void solve() {
	if (ret != NONE) {
		return;
	}

	for (int current_wall = 1; front < rear; ++current_wall) {
		int queue_size = rear - front;
		for (int i = 0; i < queue_size; ++i) {
			Position pos = queue[front++];
			dfs(pos, current_wall);
			if (ret != NONE) {
				return;
			}
		}
	}
	return;
}

int main() {
	read_input();
	init();
	solve();
	printf("%d", ret);
	return 0;
}