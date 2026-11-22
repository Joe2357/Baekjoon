#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define M 1000

int line[M];
int matrix[M][M];
int n;

void dfs(int x) {
	for (int i = line[x]; i < n; ++i) {
		if (matrix[x][i]) {
			--matrix[x][i], --matrix[i][x];
			line[x] = i;
			dfs(i);
		}
	}

	printf("%d ", x + 1);
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &matrix[i][j]);
			line[i] += matrix[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		if (line[i] % 2 != 0) {
			printf("-1");
			return 0;
		} else {
			line[i] = 0;
		}
	}

	dfs(0);
	return 0;
}