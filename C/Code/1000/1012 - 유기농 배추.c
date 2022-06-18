#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;
typedef struct Node {
	int x, y;
} ND;

#define M 50

int n, m, k;
bool matrix[M][M + 1];
ND dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(ND cur) {
	for (int i = 0; i < 4; ++i) {
		ND new = {cur.x + dir[i].x, cur.y + dir[i].y};
		if (new.x >= 0 && new.x < n&& new.y >= 0 && new.y < m && matrix[new.x][new.y]) {
			matrix[new.x][new.y] = false;
			dfs(new);
		}
	}
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		while (k--) {
			int a, b;
			scanf("%d %d", &a, &b);
			matrix[a][b] = true;
		}

		int result = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (matrix[i][j]) {
					matrix[i][j] = false;
					dfs((ND){i, j});
					++result;
				}
			}
		}

		printf("%d\n", result);
	}
	return 0;
}