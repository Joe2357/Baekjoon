#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 1000
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

typedef struct Lazer {
	int x, y;
	int direction;
} Lazer;

bool isMirrorExists[MAX_IDX + 2][MAX_IDX + 2 + 1];
int grid_number[MAX_IDX + 2][MAX_IDX + 2];
int n, m;

bool isInGrid(int x, int y) {
	return (1 <= x && x <= n && 1 <= y && y <= m);
}

void read_input() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int x;
			scanf("%d", &x);
			isMirrorExists[i][j] = (x == 1);
		}
	}

	// 왼쪽 아래방향
	int idx = 0;
	for (int i = 1; i <= n; ++i) {
		grid_number[i][0] = ++idx;
	}

	// 아래 오른쪽방향
	for (int i = 1; i <= m; ++i) {
		grid_number[n + 1][i] = ++idx;
	}

	// 오른쪽 위방향
	for (int i = n; i > 0; --i) {
		grid_number[i][m + 1] = ++idx;
	}

	// 위 왼쪽방향
	for (int i = m; i > 0; --i) {
		grid_number[0][i] = ++idx;
	}

	/*
	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= m + 1; ++j) {
			printf("%d ", grid_number[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= m + 1; ++j) {
			printf("%d ", isMirrorExists[i][j] == true);
		}
		printf("\n");
	}
	*/

	return;
}

void simulation(Lazer l) {
	while (isInGrid(l.x, l.y) == true) {
		if (isMirrorExists[l.x][l.y] == true) {
			switch (l.direction) {
				case LEFT: {
					l.direction = DOWN;
					break;
				}
				case RIGHT: {
					l.direction = UP;
					break;
				}
				case UP: {
					l.direction = RIGHT;
					break;
				}
				case DOWN: {
					l.direction = LEFT;
					break;
				}
			}
		}

		switch (l.direction) {
			case LEFT: {
				l.y -= 1;
				break;
			}
			case RIGHT: {
				l.y += 1;
				break;
			}
			case UP: {
				l.x -= 1;
				break;
			}
			case DOWN: {
				l.x += 1;
				break;
			}
		}
	}
	printf("%d ", grid_number[l.x][l.y]);
	return;
}

int main() {
	read_input();

	// 왼쪽 아래방향
	for (int i = 1; i <= n; ++i) {
		simulation((Lazer){i, 1, RIGHT});
	}

	// 아래 오른쪽방향
	for (int i = 1; i <= m; ++i) {
		simulation((Lazer){n, i, UP});
	}

	// 오른쪽 위방향
	for (int i = n; i > 0; --i) {
		simulation((Lazer){i, m, LEFT});
	}

	// 위 왼쪽방향
	for (int i = m; i > 0; --i) {
		simulation((Lazer){1, i, DOWN});
	}
	return 0;
}