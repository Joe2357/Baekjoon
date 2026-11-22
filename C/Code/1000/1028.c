#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 750
const char EMPTY = '0';
const char DIAMOND = '1';

typedef struct DPNode {
	int leftup;	 // 좌상단 누적 1의 갯수
	int rightup; // 우상단 누적 1의 갯수
} DPNode;

bool grid[MAX_IDX][MAX_IDX + 1];
int r, c;
DPNode ps[MAX_IDX][MAX_IDX];

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))

void read_input() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; ++i) {
		scanf("%s", grid[i]);
	}
	return;
}

void init() {
	// 좌상단 연속 1의 갯수 헤아림
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (grid[i][j] == DIAMOND) {
				ps[i][j].leftup = ((i > 0 && j > 0) ? ps[i - 1][j - 1].leftup + 1 : 1);
			} else {
				ps[i][j].leftup = 0;
			}
		}
	}

	// 우상단 연속 1의 갯수 헤아림
	for (int i = 0; i < r; ++i) {
		for (int j = c - 1; j >= 0; --j) {
			if (grid[i][j] == DIAMOND) {
				ps[i][j].rightup = ((i > 0 && j < c - 1) ? ps[i - 1][j + 1].rightup + 1 : 1);
			} else {
				ps[i][j].rightup = 0;
			}
		}
	}
	return;
}

void ps_debug() {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			printf("(%d|%d) ", ps[i][j].leftup, ps[i][j].rightup);
		}
		printf("\n");
	}
	return;
}

int solve() {
	int ret = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			int current_min_value = min(ps[i][j].leftup, ps[i][j].rightup);
			if (current_min_value > ret) {
				for (int k = current_min_value; k > ret; --k) {
					/**
					 * 좌상단, 우상단으로 먼저 이동 후,
					 * 그 칸으로부터 다시 우상단, 좌상단으로 이동할 수 있는지 검사
					 */
					int x = i - k + 1;
					int left_y = j - k + 1, right_y = j + k - 1;
					if (ps[x][left_y].rightup >= k && ps[x][right_y].leftup >= k) {
						ret = k;
						break;
					}
				}
			}
		}
	}
	return ret;
}

int main() {
	read_input();
	init();
	// ps_debug();
	printf("%d", solve());
	return 0;
}