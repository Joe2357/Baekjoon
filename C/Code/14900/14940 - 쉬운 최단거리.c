#include <stdio.h>

typedef struct Node {
	int x, y;
} ND;
typedef struct QueueNode {
	ND pos;
	int v;
} QN;

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 1000
const int WALL = 0;
const int EMPTY = 1;
const int GOAL = 2;

int n, m;
int grid[MAX_IDX][MAX_IDX];
int retval[MAX_IDX][MAX_IDX];
ND goal;

QN q[MAX_IDX * MAX_IDX];
bool visit[MAX_IDX][MAX_IDX + 1];
int front, rear;

#define MAX_DIR 4
ND dir[MAX_DIR] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &grid[i][j]);
			if (grid[i][j] == GOAL) {
				goal = (ND){i, j};
				q[rear++] = (QN){goal, 0};
				visit[i][j] = true;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == WALL) {
				retval[i][j] = 0;
			} else {
				retval[i][j] = -1;
			}
		}
	}

	while (front < rear) {
		QN cur = q[front++];
		retval[cur.pos.x][cur.pos.y] = cur.v;
		for (int i = 0; i < MAX_DIR; ++i) {
			ND new = (ND){cur.pos.x + dir[i].x, cur.pos.y + dir[i].y};
			if (0 <= new.x &&new.x < n && 0 <= new.y &&new.y < m) {
				if (grid[new.x][new.y] == EMPTY && visit[new.x][new.y] == false) {
					visit[new.x][new.y] = true;
					q[rear++] = (QN){new, cur.v + 1};
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d ", retval[i][j]);
		}
		printf("\n");
	}
	return 0;
}