#include <stdbool.h>
#include <stdio.h>

#define MAX_IDX 50
#define MAX_DIR 4
const char WALL = '0';

typedef struct Position {
	int x, y;
} Position;

const Position dir[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isWall[MAX_IDX][MAX_IDX];
bool visit[MAX_IDX][MAX_IDX];
int n;
int ans[MAX_IDX][MAX_IDX];

Position q[MAX_IDX * MAX_IDX + 1];
int front, rear;

void read_input() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		char str[MAX_IDX + 1];
		scanf("%s", str);
		for (int j = 0; j < n; ++j) {
			isWall[i][j] = (str[j] == WALL);
		}
	}
	return;
}

void dfs(int x, int y, int depth) {
	for (int i = 0; i < MAX_DIR; ++i) {
		Position newPos = (Position){x + dir[i].x, y + dir[i].y};
		if (0 <= newPos.x && newPos.x < n && 0 <= newPos.y && newPos.y < n) {
			if (visit[newPos.x][newPos.y] == false) {
				visit[newPos.x][newPos.y] = true;

				if (isWall[newPos.x][newPos.y] == false) {
					ans[newPos.x][newPos.y] = depth;
					dfs(newPos.x, newPos.y, depth);
				} else {
					q[rear++] = newPos;
				}
			}
		}
	}
	return;
}

void init() {
	front = rear = 0;
	dfs(0, 0, 0); // 시작점에서 시작
	return;
}

void solve() {
	int endpoint;
	for (int depth = 1; front < rear; ++depth) {
		endpoint = rear;

		while (front < endpoint) {
			Position cur = q[front++];
			isWall[cur.x][cur.y] = false, ans[cur.x][cur.y] = depth;
			dfs(cur.x, cur.y, depth);
		}
	}
	return;
}

void print_result() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return;
}

int main() {
	read_input();
	init();
	solve();
	// print_result();
	printf("%d", ans[n - 1][n - 1]);
	return 0;
}