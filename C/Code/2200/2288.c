#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Position {
	int x, y;
} PS;
typedef struct QueueNode {
	PS pos;
	int cnt;
} QN;

#define MAX_GRID 200
const char WHITE = 'W';
const char SPLITER = 'S';
const char BLACK = 'B';
const int FIRST_LINE = 0;

#define MAX_DIR 4
PS dir[MAX_DIR] = {
	{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

char grid[MAX_GRID][MAX_GRID + 1];
bool visit[MAX_GRID][MAX_GRID + 1];
int n, m;
int LAST_LINE;

QN q[MAX_GRID * MAX_GRID];
int front, rear;

bool isInTheGrid(PS cur) {
	return (
		(cur.x >= 0 && cur.x < n) &&
		(cur.y >= 0 && cur.y < m));
}
bool isCorner(PS cur) {
	return (
		(cur.x == 0 || cur.x == n - 1) &&
		(cur.y == 0 || cur.y == m - 1));
}

void init() {
	front = rear = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			visit[i][j] = false;
		}
	}
	return;
}
void addQueue(PS c, int num) {
	q[rear++] = (QN){c, num};
	return;
}

int solve() {
	int ret = 0;
	while (front < rear) {
		QN cur = q[front++];
		// printf("[System] Queue %d popped : {%d, %d / %d}\n", front, cur.pos.x, cur.pos.y, cur.cnt);

		if (cur.pos.x == LAST_LINE && isCorner(cur.pos) == false) {
			return cur.cnt;
		}

		for (int i = 0; i < MAX_DIR; ++i) {
			PS new = (PS){cur.pos.x + dir[i].x, cur.pos.y + dir[i].y};
			if (isInTheGrid(new) == true && visit[new.x][new.y] == false) {
				// 1. is it a member of splitter?
				if (grid[new.x][new.y] == SPLITER) {
					visit[new.x][new.y] = true;
					addQueue(new, cur.cnt + 1);
				}

				// 2. was it a new member of splitter?
				else if ((grid[new.x][new.y] == BLACK) && (grid[new.x][new.y - 1] == SPLITER)) {
					visit[new.x][new.y] = true;
					addQueue(new, cur.cnt + 1);
				}
			}
		}
	}
	return 0;
}

int main() {
	while (true) {
		// input
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) {
			break;
		}
		for (int i = 0; i < n; ++i) {
			scanf("%s", grid[i]);
		}

		// preprocessing
		init();
		for (int j = 0; j < m; ++j) {
			PS currentPosition = (PS){FIRST_LINE, j};
			if (grid[FIRST_LINE][j] == SPLITER &&
				isCorner(currentPosition) == false) {
				visit[FIRST_LINE][j] = true;
				addQueue(currentPosition, 1);

				PS nextPosition = (PS){FIRST_LINE, j + 1};
				if (isInTheGrid(nextPosition) == true &&
					grid[FIRST_LINE][j + 1] == BLACK &&
					isCorner(nextPosition) == false) {
					visit[FIRST_LINE][j + 1] = true;
					addQueue(nextPosition, 1);
				}
			}
		}
		LAST_LINE = n - 1;

		// solve
		printf("%d\n", solve());
	}
	return 0;
}