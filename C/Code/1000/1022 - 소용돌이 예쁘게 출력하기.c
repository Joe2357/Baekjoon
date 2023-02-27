#include <stdio.h>

typedef struct Node {
	int x, y;
} ND;

ND dir[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int digit[11] = {1, 10, 100, 1000, 10000, 100000, (int)(1e6), (int)(1e7), (int)(1e8), (int)(1e9)};
int currentDigit = 0;
int grid[50][5];
int r1, c1, r2, c2;

void fill_table() {
	ND cur = (ND){-1, 0};
	int currentDirection = 3, curLen = 1;
	int fillCount = (r2 - r1 + 1) * (c2 - c1 + 1);

	int x = 0;
	while (fillCount > 0) {
		for (int i = 0; i < curLen; ++i) {
			cur.x += dir[currentDirection].x, cur.y += dir[currentDirection].y;
			++x;

			if (r1 <= cur.x && cur.x <= r2 && c1 <= cur.y && cur.y <= c2) {
				grid[cur.x - r1][cur.y - c1] = x;
				--fillCount;
			}
			if (digit[currentDigit] == x) {
				++currentDigit;
			}
			if (fillCount == 0) {
				return;
			}
		}

		switch (currentDirection) {
			case 0: {
				currentDirection = 1;
				break;
			}
			case 1: {
				currentDirection = 2;
				++curLen;
				break;
			}
			case 2: {
				currentDirection = 3;
				break;
			}
			case 3: {
				currentDirection = 0;
				if (x > 1) {
					++curLen;
				}
				break;
			}
		}
	}

	return;
}

void print_table() {
	for (int i = 0; i <= r2 - r1; ++i) {
		for (int j = 0; j <= c2 - c1; ++j) {
			switch (currentDigit) {
				case 1: {
					printf("%1d ", grid[i][j]);
					break;
				}
				case 2: {
					printf("%2d ", grid[i][j]);
					break;
				}
				case 3: {
					printf("%3d ", grid[i][j]);
					break;
				}
				case 4: {
					printf("%4d ", grid[i][j]);
					break;
				}
				case 5: {
					printf("%5d ", grid[i][j]);
					break;
				}
				case 6: {
					printf("%6d ", grid[i][j]);
					break;
				}
				case 7: {
					printf("%7d ", grid[i][j]);
					break;
				}
				case 8: {
					printf("%8d ", grid[i][j]);
					break;
				}
				case 9: {
					printf("%9d ", grid[i][j]);
					break;
				}
				case 10: {
					printf("%10d ", grid[i][j]);
					break;
				}
			}
		}
		printf("\n");
	}
	return;
}

int main() {
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

	fill_table();
	print_table();
	return 0;
}