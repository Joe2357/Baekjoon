#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

typedef struct Position {
	int x, y;
} Position;
typedef struct QueueNode {
	Position pos;
	int dist;
} QueueNode;

#define MAX_IDX 100
#define MAX_DIR 4
const int EMPTY = 0;
const int NONE = -1;
const int INF = 987654321;

const Position dir[MAX_DIR] = {
	{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool grid[MAX_IDX][MAX_IDX + 1];
int group[MAX_IDX][MAX_IDX + 1];
int n;

QueueNode q[MAX_IDX * MAX_IDX];
int front, rear;

#define min(a, b) (((a) > (b)) ? (b) : (a))

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int a;
			scanf("%d", &a);
			grid[i][j] = (a == 1);
		}
	}
	return;
}

bool is_valid_position(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < n);
}

void make_group(Position p, int group_num) {
	bool visit[MAX_IDX][MAX_IDX + 1] = {false};
	front = rear = 0;

	visit[p.x][p.y] = true;
	q[rear++] = (QueueNode){p, 0};

	while (front < rear) {
		QueueNode qn = q[front++];
		Position cur = qn.pos;
		group[cur.x][cur.y] = group_num;

		for (int d = 0; d < MAX_DIR; ++d) {
			int nx = cur.x + dir[d].x;
			int ny = cur.y + dir[d].y;

			if (is_valid_position(nx, ny) == true && visit[nx][ny] == false && grid[nx][ny] == true) {
				visit[nx][ny] = true;
				q[rear++] = (QueueNode){(Position){nx, ny}, 0};
			}
		}
	}
	return;
}

void init() {
	int group_cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == true && group[i][j] == EMPTY) {
				make_group((Position){i, j}, ++group_cnt);
			}
		}
	}
	return;
}

void print_group() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", group[i][j]);
		}
		printf("\n");
	}
	return;
}

int bfs(Position s) {
	bool visit[MAX_IDX][MAX_IDX + 1] = {false};
	front = rear = 0;

	visit[s.x][s.y] = true;
	q[rear++] = (QueueNode){s, 0};
	int current_group_num = group[s.x][s.y];

	int ret = INF + 1;
	while (front < rear) {
		QueueNode qn = q[front++];
		Position cur = qn.pos;

		if (group[cur.x][cur.y] != EMPTY && group[cur.x][cur.y] != current_group_num) {
			ret = qn.dist;
			break;
		}

		for (int d = 0; d < MAX_DIR; ++d) {
			int nx = cur.x + dir[d].x;
			int ny = cur.y + dir[d].y;

			if (is_valid_position(nx, ny) == true && visit[nx][ny] == false && group[nx][ny] != current_group_num) {
				visit[nx][ny] = true;
				q[rear++] = (QueueNode){(Position){nx, ny}, qn.dist + 1};
			}
		}
	}
	return ret;
}

int main() {
	read_input();
	init();
	// print_group();

	int ret = INF;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == true) {
				int temp = bfs((Position){i, j});
				ret = min(ret, temp - 1);
			}
		}
	}
	printf("%d", ret);
	return 0;
}