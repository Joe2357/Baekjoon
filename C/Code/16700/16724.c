#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Position {
	int x, y;
} Position;

#define MAX_IDX 1000
#define UP 'U'
#define DOWN 'D'
#define LEFT 'L'
#define RIGHT 'R'

typedef int status;
const status STATUS_UNVISITED = 0;
const status STATUS_VISITING = 1;
const status STATUS_VISITED = 2;

int n, m;
char grid[MAX_IDX + 1][MAX_IDX + 1 + 1];
status visit[MAX_IDX + 1][MAX_IDX + 1 + 1];

void dfs(Position pos, int* ret) {
	visit[pos.x][pos.y] = STATUS_VISITING;

	Position next = pos;
	switch (grid[pos.x][pos.y]) {
		case UP: {
			next.x -= 1;
			break;
		}
		case DOWN: {
			next.x += 1;
			break;
		}
		case LEFT: {
			next.y -= 1;
			break;
		}
		case RIGHT: {
			next.y += 1;
			break;
		}
	}

	if (visit[next.x][next.y] == STATUS_UNVISITED) {
		dfs(next, ret);
	} else if (visit[next.x][next.y] == STATUS_VISITING) {
		(*ret) += 1;
		visit[next.x][next.y] = STATUS_VISITED;
	} else if (visit[next.x][next.y] == STATUS_VISITED) {
	} else {
	}

	visit[pos.x][pos.y] = STATUS_VISITED;
	return;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", grid[i]);
	}

	// grid_visit_init();

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (visit[i][j] == STATUS_UNVISITED) {
				Position pos = {i, j};
				dfs(pos, &ret);
			}
		}
	}

	printf("%d", ret);
	return 0;
}