#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 100
#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

typedef struct Position {
	int x, y;
} Position;
typedef struct Shark {
	int speed;
	int direction;
	int size;
} Shark;

Shark grid[MAX_IDX + 1][MAX_IDX + 1];
int r, c;

#define abs(x) ((x) < 0 ? (-(x)) : (x))

void clear_shark(int x, int y) {
	grid[x][y] = (Shark){0, 0};
	return;
}
void place_shark(Shark s, int x, int y) {
	int current_size = grid[x][y].size;
	if (s.size > current_size) {
		grid[x][y] = s;
	}
	return;
}
int catch_column(int y) {
	for (int i = 1; i <= r; ++i) {
		if (grid[i][y].size > 0) { // 상어가 있음
			Shark catched = grid[i][y];
			clear_shark(i, y);
			return catched.size;
		}
	}
	return 0;
}

void read_input() {
	int m;
	scanf("%d %d %d", &r, &c, &m);
	while (m--) {
		int x, y, s, d, z;
		scanf("%d %d %d %d %d", &x, &y, &s, &d, &z);
		place_shark((Shark){s, d, z}, x, y);
	}
	return;
}

void move_all_sharks() {
	// 이전 state 저장 및 현재 state 초기화
	Shark prev[MAX_IDX + 1][MAX_IDX + 1];
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			prev[i][j] = grid[i][j];
			clear_shark(i, j);
		}
	}

	// 모든 상어들의 위치 재계산 및 재배치
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (prev[i][j].size > 0) {
				int x = i, y = j;
				int d = prev[i][j].direction, s = prev[i][j].speed;

				// 칸 이동
				switch (d) {
					case UP: {
						x -= (s % (2 * (r - 1)));
						break;
					}
					case DOWN: {
						x += (s % (2 * (r - 1)));
						break;
					}
					case RIGHT: {
						y += (s % (2 * (c - 1)));
						break;
					}
					case LEFT: {
						y -= (s % (2 * (c - 1)));
						break;
					}
				}

				// 범위 밖인 경우 : 방향을 전환해야하는 경우
				if (x < 1) {
					d = DOWN;
					x = 1 + abs(1 - x);
				}
				if (x > r) {
					d = UP;
					x = r - abs(r - x);
				}
				if (y < 1) {
					d = RIGHT;
					y = 1 + abs(1 - y);
				}
				if (y > c) {
					d = LEFT;
					y = c - abs(c - y);
				}

				// 방향을 2번 바꿔야할 수도 있으니 더블 체크
				if (x < 1) {
					d = DOWN;
					x = 1 + abs(1 - x);
				}
				if (x > r) {
					d = UP;
					x = r - abs(r - x);
				}
				if (y < 1) {
					d = RIGHT;
					y = 1 + abs(1 - y);
				}
				if (y > c) {
					d = LEFT;
					y = c - abs(c - y);
				}

				prev[i][j].direction = d;
				place_shark(prev[i][j], x, y);
			}
		}
	}

	return;
}

int main() {
	read_input(); // init();

	int ret = 0;
	for (int y = 1; y <= c; ++y) { // move();
		ret += catch_column(y);
		move_all_sharks();
	}

	printf("%d", ret);
	return 0;
}