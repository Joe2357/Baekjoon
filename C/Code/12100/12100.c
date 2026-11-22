#include <stdio.h>

#define MAX_IDX 20
#define MAX_MOVE 5

int n;
int answer;

#define max(a, b) (((a) > (b)) ? (a) : (b))

void backtrack(int map[][MAX_IDX], int cnt) {
	if (cnt == MAX_MOVE) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				answer = max(answer, map[i][j]);
			}
		}
		return;
	}
	int grid[MAX_IDX][MAX_IDX];

	// RIGHT
	{
		for (int a = 0; a < n; ++a) {
			for (int b = 0; b < n; ++b) {
				grid[a][b] = map[a][b];
			}
		}

		for (int a = 0; a < n; ++a) {
			int blockIndex = n, mergedIndex = n;
			if (grid[a][n - 1] != 0) {
				--blockIndex;
			}
			for (int b = n - 2; b >= 0; --b) {
				if (grid[a][b] > 0) {
					if (blockIndex != n && (grid[a][b] == grid[a][blockIndex] && blockIndex < mergedIndex)) {
						grid[a][blockIndex] <<= 1;
						mergedIndex = blockIndex;
					} else {
						grid[a][--blockIndex] = grid[a][b];
					}
					if (b < blockIndex) {
						grid[a][b] = 0;
					}
				}
			}
		}
		backtrack(grid, cnt + 1);
	}

	// DOWN
	{
		for (int a = 0; a < n; ++a) {
			for (int b = 0; b < n; ++b) {
				grid[a][b] = map[a][b];
			}
		}

		for (int a = 0; a < n; ++a) {
			int blockIndex = n, mergedIndex = n;
			if (grid[n - 1][a] != 0) {
				--blockIndex;
			}
			for (int b = n - 2; b >= 0; --b) {
				if (grid[b][a] > 0) {
					if (blockIndex != n && (grid[b][a] == grid[blockIndex][a] && blockIndex < mergedIndex)) {
						grid[blockIndex][a] <<= 1;
						mergedIndex = blockIndex;
					} else {
						grid[--blockIndex][a] = grid[b][a];
					}
					if (b < blockIndex) {
						grid[b][a] = 0;
					}
				}
			}
		}
		backtrack(grid, cnt + 1);
	}

	// LEFT
	{
		for (int a = 0; a < n; ++a) {
			for (int b = 0; b < n; ++b) {
				grid[a][b] = map[a][b];
			}
		}

		for (int a = 0; a < n; ++a) {
			int blockIndex = -1, mergedIndex = -1;
			if (grid[a][0] != 0) {
				++blockIndex;
			}
			for (int b = 1; b < n; ++b) {
				if (grid[a][b] > 0) {
					if (blockIndex != -1 && (grid[a][b] == grid[a][blockIndex] && blockIndex > mergedIndex)) {
						grid[a][blockIndex] <<= 1;
						mergedIndex = blockIndex;
					} else {
						grid[a][++blockIndex] = grid[a][b];
					}
					if (b > blockIndex) {
						grid[a][b] = 0;
					}
				}
			}
		}
		backtrack(grid, cnt + 1);
	}

	// UP
	{
		for (int a = 0; a < n; ++a) {
			for (int b = 0; b < n; ++b) {
				grid[a][b] = map[a][b];
			}
		}

		for (int a = 0; a < n; ++a) {
			int blockIndex = -1, mergedIndex = -1;
			if (grid[0][a] != 0) {
				++blockIndex;
			}
			for (int b = 1; b < n; ++b) {
				if (grid[b][a] > 0) {
					if (blockIndex != -1 && (grid[b][a] == grid[blockIndex][a] && blockIndex > mergedIndex)) {
						grid[blockIndex][a] <<= 1;
						mergedIndex = blockIndex;
					} else {
						grid[++blockIndex][a] = grid[b][a];
					}
					if (b > blockIndex) {
						grid[b][a] = 0;
					}
				}
			}
		}
		backtrack(grid, cnt + 1);
	}

	return;
}

int main() {
	int grid[MAX_IDX][MAX_IDX];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &grid[i][j]);
		}
	}

	backtrack(grid, 0);
	printf("%d", answer);
	return 0;
}