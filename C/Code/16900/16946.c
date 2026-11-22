#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 1000
const char WALL = '1';
const char EMPTY = '0';
const int DIGIT = 10;
const int NOT_DETERMINE = 0;
const int NONE = -1;

typedef struct Point {
	int x, y;
} Point;

char grid[MAX_IDX][MAX_IDX + 1];
char ans[MAX_IDX][MAX_IDX + 1];
int n, m;

int group[MAX_IDX][MAX_IDX];
int group_size[MAX_IDX * MAX_IDX];

#define MAX_DIR 4
Point dir[MAX_DIR] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
Point queue[MAX_IDX * MAX_IDX];
int front, rear;

void read_input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", grid[i]);
	}
	return;
}

void init() {
	int cur = 0;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (grid[x][y] == EMPTY && group[x][y] == NOT_DETERMINE) {
				front = rear = 0;
				queue[rear++] = (Point){x, y};
				group[x][y] = ++cur;
				group_size[cur] = 1;

				while (front < rear) {
					Point p = queue[front++];
					for (int d = 0; d < MAX_DIR; ++d) {
						Point next = (Point){p.x + dir[d].x, p.y + dir[d].y};
						if (0 <= next.x && next.x < n && 0 <= next.y && next.y < m) {
							if (grid[next.x][next.y] == EMPTY && group[next.x][next.y] == NOT_DETERMINE) {
								group[next.x][next.y] = cur;
								++group_size[cur];
								queue[rear++] = next;
							}
						}
					}
				}
			}
		}
	}
	return;
}

void solve() {
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (grid[x][y] == WALL) {
				int sum = 1;
				int group_up, group_down, group_left, group_right;

				// UP
				if (x > 0 && grid[x - 1][y] == EMPTY) {
					group_up = group[x - 1][y];
					sum += group_size[group_up];
				} else {
					group_up = NONE;
				}

				// DOWN
				if (x + 1 < n && grid[x + 1][y] == EMPTY) {
					group_down = group[x + 1][y];
					if (group_down != group_up) {
						sum += group_size[group_down];
					}
				} else {
					group_down = NONE;
				}

				// LEFT
				if (y > 0 && grid[x][y - 1] == EMPTY) {
					group_left = group[x][y - 1];
					if (group_left != group_up && group_left != group_down) {
						sum += group_size[group_left];
					}
				} else {
					group_left = NONE;
				}

				// RIGHT
				if (y + 1 < m && grid[x][y + 1] == EMPTY) {
					group_right = group[x][y + 1];
					if (group_right != group_up && group_right != group_down && group_right != group_left) {
						sum += group_size[group_right];
					}
				} else {
					group_right = NONE;
				}

				ans[x][y] = (sum % DIGIT) + '0';
			} else {
				ans[x][y] = EMPTY;
			}
		}
	}
	return;
}

void print_output() {
	for (int i = 0; i < n; ++i) {
		printf("%s\n", ans[i]);
	}
	return;
}

int main() {
	read_input();
	init();
	solve();
	print_output();
	return 0;
}