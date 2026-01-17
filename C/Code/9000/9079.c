#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_SIZE 3
#define MAX_OPERATIONS 8
const int INF = 987654321;
const int NONE = -1;

const char HEAD = 'H';
const char TAIL = 'T';

typedef struct Queue {
	int operation_cnt;
	int visited;
} Queue;

char grid[MAX_SIZE][MAX_SIZE + 1];

#define min(a, b) ((a) < (b) ? (a) : (b))

void read_grid() {
	for (int i = 0; i < MAX_SIZE; ++i) {
		for (int j = 0; j < MAX_SIZE; ++j) {
			scanf(" %c", &grid[i][j]);
		}
	}
}

char flip(char c) {
	return (c == HEAD) ? TAIL : HEAD;
}

/* 연산 리스트
 * 0: 첫째 행 뒤집기
 * 1: 둘째 행 뒤집기
 * 2: 셋째 행 뒤집기
 * 3: 첫째 열 뒤집기
 * 4: 둘째 열 뒤집기
 * 5: 셋째 열 뒤집기
 * 6: 대각선(좌상-우하) 뒤집기
 * 7: 대각선(우상-좌하) 뒤집기
 */
bool isAllSame(int operations) {
	char new_grid[MAX_SIZE][MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; ++i) {
		for (int j = 0; j < MAX_SIZE; ++j) {
			new_grid[i][j] = grid[i][j];
		}
	}

	for (int i = 0; i < MAX_OPERATIONS; ++i) {
		if ((operations & (1 << i)) != 0) {
			switch (i) {
				case 0: { // 첫째 행 뒤집기
					for (int j = 0; j < MAX_SIZE; ++j) {
						new_grid[0][j] = flip(new_grid[0][j]);
					}
					break;
				}
				case 1: { // 둘째 행 뒤집기
					for (int j = 0; j < MAX_SIZE; ++j) {
						new_grid[1][j] = flip(new_grid[1][j]);
					}
					break;
				}
				case 2: { // 셋째 행 뒤집기
					for (int j = 0; j < MAX_SIZE; ++j) {
						new_grid[2][j] = flip(new_grid[2][j]);
					}
					break;
				}
				case 3: { // 첫째 열 뒤집기
					for (int j = 0; j < MAX_SIZE; ++j) {
						new_grid[j][0] = flip(new_grid[j][0]);
					}
					break;
				}
				case 4: { // 둘째 열 뒤집기
					for (int j = 0; j < MAX_SIZE; ++j) {
						new_grid[j][1] = flip(new_grid[j][1]);
					}
					break;
				}
				case 5: { // 셋째 열 뒤집기
					for (int j = 0; j < MAX_SIZE; ++j) {
						new_grid[j][2] = flip(new_grid[j][2]);
					}
					break;
				}
				case 6: { // 대각선(좌상-우하) 뒤집기
					for (int j = 0; j < MAX_SIZE; ++j) {
						new_grid[j][j] = flip(new_grid[j][j]);
					}
					break;
				}
				case 7: { // 대각선(우상-좌하) 뒤집기
					for (int j = 0; j < MAX_SIZE; ++j) {
						new_grid[j][MAX_SIZE - 1 - j] = flip(new_grid[j][MAX_SIZE - 1 - j]);
					}
					break;
				}
			}
		}
	}

	bool ret = true;
	for (int i = 0; i < MAX_SIZE; ++i) {
		for (int j = 0; j < MAX_SIZE; ++j) {
			ret &= (new_grid[i][j] == new_grid[0][0]);
		}
	}
	return ret;
}

int getOperationCount(int operations) {
	int ret = 0;
	for (int i = 0; i < MAX_OPERATIONS; ++i) {
		ret += ((operations & (1 << i)) != 0);
	}
	return ret;
}

int solve() {
	int ret = INF;
	for (int operation = 0; operation < (1 << MAX_OPERATIONS); ++operation) {
		if (isAllSame(operation) == true) {
			ret = min(ret, getOperationCount(operation));
		}
	}
	return (ret == INF) ? NONE : ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		read_grid();
		printf("%d\n", solve());
	}
	return 0;
}