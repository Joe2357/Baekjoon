#include <stdio.h>

const int INF = 987654321;
#define MAX_IDX 200
const int NONE = -1;

int grid[MAX_IDX + 1][MAX_IDX + 1];
int table[MAX_IDX + 1][MAX_IDX + 1];
int n, m;

void init() {
	for (int i = 1; i <= MAX_IDX; ++i) {
		for (int j = 1; j <= MAX_IDX; ++j) {
			grid[i][j] = INF;
			table[i][j] = NONE;
		}
	}
	return;
}

void read_input() {
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (grid[a][b] > c) {
			grid[a][b] = c;
			table[a][b] = b;
		}

		if (grid[b][a] > c) {
			grid[b][a] = c;
			table[b][a] = a;
		}
	}
	return;
}

int main() {
	init();
	read_input();

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (grid[i][j] > grid[i][k] + grid[k][j]) {
					grid[i][j] = grid[i][k] + grid[k][j];
					table[i][j] = table[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) {
				printf("- ");
			} else {
				printf("%d ", table[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}