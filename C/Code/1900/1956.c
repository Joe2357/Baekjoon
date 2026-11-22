#include <stdio.h>

#define MAX_IDX 400
#define INF 987654321

int grid[MAX_IDX + 1][MAX_IDX + 1];
int v, e;
int result = INF;

#define min(a, b) (((a) > (b)) ? (b) : (a))

void init() {
	for (int i = 1; i <= v; ++i) {
		for (int j = 1; j <= v; ++j) {
			grid[i][j] = INF;
		}
	}
	return;
}

int main() {
	scanf("%d %d", &v, &e);
	init();

	while (e--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		grid[a][b] = c;
	}

	for (int k = 1; k <= v; ++k) {
		for (int i = 1; i <= v; ++i) {
			for (int j = 1; j <= v; ++j) {
				grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
			}
		}
	}

	for (int i = 1; i <= v; ++i) {
		result = min(result, grid[i][i]);
	}

	if (result == INF) {
		printf("-1");
	} else {
		printf("%d", result);
	}
	return 0;
}