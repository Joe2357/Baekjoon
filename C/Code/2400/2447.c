#include <stdio.h>

#define MAX_IDX (6561 + 1)
char grid[MAX_IDX][MAX_IDX];

const int false = 0;

void getStar(int x, int y, int n) {
	if (n == 1) {
		grid[x][y] = '*';
	} else {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if ((i == 1 && j == 1) == false) {
					getStar(x + (n / 3) * i, y + (n / 3) * j, n / 3);
				}
			}
		}
	}
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			grid[i][j] = ' ';
		}
		grid[i][n] = '\0';
	}

	getStar(0, 0, n);
	for (int i = 0; i < n; ++i) {
		printf("%s\n", grid[i]);
	}
	return 0;
}