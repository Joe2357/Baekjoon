#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define GRID_SIZE 19
const int BLACK = 1;
const int WHITE = 2;
const int EMPTY = 0;

int grid[GRID_SIZE][GRID_SIZE];

void read_input() {
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			scanf("%d", &grid[i][j]);
		}
	}
	return;
}

// 시작점 :: (x, y)
// 4가지 경우를 고려해야 함
bool check_position(int x, int y) {
	//   1. 가로 방향 (-)
	if (y <= GRID_SIZE - 5) {
		if (grid[x][y] == grid[x][y + 1] &&
			grid[x][y] == grid[x][y + 2] &&
			grid[x][y] == grid[x][y + 3] &&
			grid[x][y] == grid[x][y + 4]) {

			if (y == (GRID_SIZE - 5) || grid[x][y] != grid[x][y + 5]) {
				if (y == 0 || grid[x][y] != grid[x][y - 1]) {
					return true;
				}
			}
		}
	}

	//   2. 세로 방향 (|)
	if (x <= GRID_SIZE - 5) {
		if (grid[x][y] == grid[x + 1][y] &&
			grid[x][y] == grid[x + 2][y] &&
			grid[x][y] == grid[x + 3][y] &&
			grid[x][y] == grid[x + 4][y]) {

			if (x == (GRID_SIZE - 5) || grid[x][y] != grid[x + 5][y]) {
				if (x == 0 || grid[x][y] != grid[x - 1][y]) {
					return true;
				}
			}
		}
	}

	//   3. 대각선 방향 (\)
	if (x <= GRID_SIZE - 5 && y <= GRID_SIZE - 5) {
		if (grid[x][y] == grid[x + 1][y + 1] &&
			grid[x][y] == grid[x + 2][y + 2] &&
			grid[x][y] == grid[x + 3][y + 3] &&
			grid[x][y] == grid[x + 4][y + 4]) {

			if (x == (GRID_SIZE - 5) || y == (GRID_SIZE - 5) || grid[x][y] != grid[x + 5][y + 5]) {
				if (x == 0 || y == 0 || grid[x][y] != grid[x - 1][y - 1]) {
					return true;
				}
			}
		}
	}

	//   4. 대각선 방향 (/)
	if (x >= 4 && y <= GRID_SIZE - 5) {
		if (grid[x][y] == grid[x - 1][y + 1] &&
			grid[x][y] == grid[x - 2][y + 2] &&
			grid[x][y] == grid[x - 3][y + 3] &&
			grid[x][y] == grid[x - 4][y + 4]) {

			if (x == 4 || y == (GRID_SIZE - 5) || grid[x][y] != grid[x - 5][y + 5]) {
				if (x == (GRID_SIZE - 1) || y == 0 || grid[x][y] != grid[x + 1][y - 1]) {
					return true;
				}
			}
		}
	}

	// 아무것도 해당하지 않는 경우
	return false;
}

int main() {
	read_input();

	bool isAnswerFound = false;
	for (int x = 0; x < GRID_SIZE; ++x) {
		for (int y = 0; y < GRID_SIZE; ++y) {
			if (isAnswerFound == true) {
				break;
			}

			if (grid[x][y] != EMPTY) {
				if (check_position(x, y) == true) {
					printf("%d\n%d %d", grid[x][y], x + 1, y + 1);
					isAnswerFound = true;
				}
			}
		}
	}

	if (isAnswerFound == false) {
		printf("0");
	}
	return 0;
}