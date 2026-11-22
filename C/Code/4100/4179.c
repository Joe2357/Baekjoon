#include <stdbool.h>
#include <stdio.h>

#define MAX_IDX 1000
#define MAX_DIR 4
const int NONE = -1;
const char WALL = '#';
const char EMPTY = '.';
const char FIRE = 'F';

typedef struct Position {
	int x, y;
} Position;

Position dir[MAX_DIR] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

char grid[MAX_IDX][MAX_IDX + 1];
bool p_visit[MAX_IDX][MAX_IDX];
bool f_visit[MAX_IDX][MAX_IDX];
int r, c;
Position start;

Position p_q[MAX_IDX * MAX_IDX], f_q[MAX_IDX * MAX_IDX];
int p_front, p_rear;
int f_front, f_rear;

void read_input() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; ++i) {
		scanf("%s", grid[i]);
		for (int j = 0; j < c; ++j) {
			if (grid[i][j] == 'J') {
				p_visit[i][j] = true;
				p_q[p_rear++] = (Position){i, j};
				grid[i][j] = EMPTY;
			} else if (grid[i][j] == FIRE) {
				f_visit[i][j] = true;
				f_q[f_rear++] = (Position){i, j};
			}
		}
	}
	return;
}

void print_map() {
	for (int i = 0; i < r; ++i) {
		printf("%s\n", grid[i]);
	}
	printf("\n");
	return;
}

int solve() {
	int ret = NONE;

	for (int time = 1; ret == NONE && p_front < p_rear; ++time) {
		// print_map();

		// 사람 이동
		for (int endpoint = p_rear; p_front < endpoint; ++p_front) {
			Position cur = p_q[p_front];
			if (grid[cur.x][cur.y] == FIRE) { // 불이 옮겨붙음
				continue;
			}

			for (int i = 0; i < MAX_DIR; ++i) {
				Position nextPos = (Position){cur.x + dir[i].x, cur.y + dir[i].y};
				if (0 <= nextPos.x && nextPos.x < r && 0 <= nextPos.y && nextPos.y < c) { // 범위 안에 있는 경우
					if (p_visit[nextPos.x][nextPos.y] == false && grid[nextPos.x][nextPos.y] == EMPTY) {
						p_visit[nextPos.x][nextPos.y] = true;
						p_q[p_rear++] = nextPos;
					}
				} else { // 사람이 탈출함
					ret = time;
					break;
				}
			}
		}
		if (ret != NONE) {
			break;
		}

		// 불 이동
		for (int endpoint = f_rear; f_front < endpoint; ++f_front) {
			Position cur = f_q[f_front];
			for (int i = 0; i < MAX_DIR; ++i) {
				Position nextPos = (Position){cur.x + dir[i].x, cur.y + dir[i].y};
				if (0 <= nextPos.x && nextPos.x < r && 0 <= nextPos.y && nextPos.y < c) {
					if (f_visit[nextPos.x][nextPos.y] == false && grid[nextPos.x][nextPos.y] == EMPTY) {
						f_visit[nextPos.x][nextPos.y] = true;
						grid[nextPos.x][nextPos.y] = FIRE;
						f_q[f_rear++] = nextPos;
					}
				}
			}
		}
	}
	return ret;
}

int main() {
	read_input();
	int ret = solve();

	if (ret == NONE) {
		printf("IMPOSSIBLE");
	} else {
		printf("%d", ret);
	}
	return 0;
}