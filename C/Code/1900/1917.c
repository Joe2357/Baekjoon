#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 6
#define MAX_DRAW (11 * 2 * 4)
const int TOTAL_TESTCASE = 3;
const int TRUE = 1, FALSE = 0;

typedef struct draw {
	int size_x, size_y;
	bool grid[MAX_IDX][MAX_IDX + 1 + 1];
} Draw;

bool grid[MAX_IDX][MAX_IDX + 1 + 1];
Draw draws[MAX_DRAW];

void clear_grid(bool g[MAX_IDX][MAX_IDX + 2]) {
	for (int i = 0; i < MAX_IDX; i++) {
		for (int j = 0; j < MAX_IDX + 2; j++) {
			g[i][j] = false;
		}
	}
	return;
}

void rotate90(Draw* src, Draw* dst) {
	clear_grid(dst->grid);
	dst->size_x = src->size_y;
	dst->size_y = src->size_x;

	for (int x = 0; x < src->size_x; ++x) {
		for (int y = 0; y < src->size_y; ++y) {
			if (src->grid[x][y] == true) {
				dst->grid[y][src->size_x - 1 - x] = true;
			}
		}
	}
	return;
}

void flip_horizontal(Draw* src, Draw* dst) {
	clear_grid(dst->grid);
	dst->size_x = src->size_x;
	dst->size_y = src->size_y;

	for (int x = 0; x < src->size_x; ++x) {
		for (int y = 0; y < src->size_y; ++y) {
			if (src->grid[x][y] == true) {
				dst->grid[x][src->size_y - 1 - y] = true;
			}
		}
	}
	return;
}

void init() {
	int idx = 0;

	// 1번
	draws[idx].size_x = 3, draws[idx].size_y = 4;
	draws[idx].grid[0][0] = true;
	draws[idx].grid[1][0] = true, draws[idx].grid[1][1] = true, draws[idx].grid[1][2] = true, draws[idx].grid[1][3] = true;
	draws[idx].grid[2][0] = true;
	idx += 8;

	// 2번
	draws[idx].size_x = 3, draws[idx].size_y = 4;
	draws[idx].grid[0][1] = true;
	draws[idx].grid[1][0] = true, draws[idx].grid[1][1] = true, draws[idx].grid[1][2] = true, draws[idx].grid[1][3] = true;
	draws[idx].grid[2][0] = true;
	idx += 8;

	// 3번
	draws[idx].size_x = 3, draws[idx].size_y = 4;
	draws[idx].grid[0][2] = true;
	draws[idx].grid[1][0] = true, draws[idx].grid[1][1] = true, draws[idx].grid[1][2] = true, draws[idx].grid[1][3] = true;
	draws[idx].grid[2][0] = true;
	idx += 8;

	// 4번
	draws[idx].size_x = 3, draws[idx].size_y = 4;
	draws[idx].grid[0][3] = true;
	draws[idx].grid[1][0] = true, draws[idx].grid[1][1] = true, draws[idx].grid[1][2] = true, draws[idx].grid[1][3] = true;
	draws[idx].grid[2][0] = true;
	idx += 8;

	// 5번
	draws[idx].size_x = 3, draws[idx].size_y = 4;
	draws[idx].grid[0][1] = true;
	draws[idx].grid[1][0] = true, draws[idx].grid[1][1] = true, draws[idx].grid[1][2] = true, draws[idx].grid[1][3] = true;
	draws[idx].grid[2][1] = true;
	idx += 8;

	// 6번
	draws[idx].size_x = 3, draws[idx].size_y = 4;
	draws[idx].grid[0][2] = true;
	draws[idx].grid[1][0] = true, draws[idx].grid[1][1] = true, draws[idx].grid[1][2] = true, draws[idx].grid[1][3] = true;
	draws[idx].grid[2][1] = true;
	idx += 8;

	// 7번
	draws[idx].size_x = 2, draws[idx].size_y = 5;
	draws[idx].grid[0][2] = true, draws[idx].grid[0][3] = true, draws[idx].grid[0][4] = true;
	draws[idx].grid[1][0] = true, draws[idx].grid[1][1] = true, draws[idx].grid[1][2] = true;
	idx += 8;

	// 8번
	draws[idx].size_x = 3, draws[idx].size_y = 4;
	draws[idx].grid[0][2] = true, draws[idx].grid[0][3] = true;
	draws[idx].grid[1][1] = true, draws[idx].grid[1][2] = true;
	draws[idx].grid[2][0] = true, draws[idx].grid[2][1] = true;
	idx += 8;

	// 9번
	draws[idx].size_x = 3, draws[idx].size_y = 4;
	draws[idx].grid[0][2] = true, draws[idx].grid[0][3] = true;
	draws[idx].grid[1][0] = true, draws[idx].grid[1][1] = true, draws[idx].grid[1][2] = true;
	draws[idx].grid[2][0] = true;
	idx += 8;

	// 10번
	draws[idx].size_x = 3, draws[idx].size_y = 4;
	draws[idx].grid[0][0] = true, draws[idx].grid[0][1] = true;
	draws[idx].grid[1][1] = true, draws[idx].grid[1][2] = true, draws[idx].grid[1][3] = true;
	draws[idx].grid[2][1] = true;
	idx += 8;

	// 11번
	draws[idx].size_x = 3, draws[idx].size_y = 4;
	draws[idx].grid[0][1] = true;
	draws[idx].grid[1][0] = true, draws[idx].grid[1][1] = true, draws[idx].grid[1][2] = true;
	draws[idx].grid[2][2] = true, draws[idx].grid[2][3] = true;
	idx += 8;

	// 회전 + 반전 자동 생성
	for (int base = 0; base < MAX_DRAW; base += 8) {
		// 회전
		for (int r = 1; r < 4; ++r) {
			rotate90(&draws[base + r - 1], &draws[base + r]);
		}

		// 반전
		for (int r = 0; r < 4; ++r) {
			flip_horizontal(&draws[base + r], &draws[base + r + 4]);
		}
	}

	return;
}

void read_input() {
	for (int i = 0; i < MAX_IDX; ++i) {
		for (int j = 0; j < MAX_IDX; ++j) {
			int x;
			scanf("%d", &x);
			grid[i][j] = (x == TRUE);
		}
	}
	return;
}

int main() {
	init();

	int t = TOTAL_TESTCASE;
	while (t--) {
		read_input();

		bool isAnswerExists = false;
		for (int i = 0; i < MAX_DRAW; ++i) {

			for (int x = 0; x <= MAX_IDX - draws[i].size_x; ++x) {
				for (int y = 0; y <= MAX_IDX - draws[i].size_y; ++y) {
					bool current_state = true;

					for (int tx = 0; tx < draws[i].size_x; ++tx) {
						for (int ty = 0; ty < draws[i].size_y; ++ty) {
							if (grid[x + tx][y + ty] != draws[i].grid[tx][ty]) {
								current_state = false;
								break;
							}
						}
						if (current_state == false) {
							break;
						}
					}

					if (current_state == true) {
						isAnswerExists = true;
						break;
					}
				}
				if (isAnswerExists == true) {
					break;
				}
			}
			if (isAnswerExists == true) {
				break;
			}
		}
		printf("%s\n", (isAnswerExists == true) ? "yes" : "no");
	}
	return 0;
}