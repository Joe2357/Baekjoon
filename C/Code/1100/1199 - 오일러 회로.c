#include <stdio.h>

#define MAX_INDEX (int)1e3
int matrix[MAX_INDEX][MAX_INDEX];
int n;

void dfs(int idx) {
	for (int i = 0; i < n; ++i) { // check all vertaxs
		if (matrix[idx][i] > 0) { // if there is an edge
			// remove one edge
			--matrix[idx][i], --matrix[i][idx];
			dfs(i);
		}
	}

	// if no edges left
	printf("%d ", idx + 1);
	return;
}

int main() {
	// init
	scanf("%d", &n);
	int line[MAX_INDEX] = { 0 };
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			scanf("%d", &matrix[i][j]);
			line[i] += matrix[i][j];
		}

	// find start position
	// check whether there is odd-edge vertax
	for (int i = 0; i < n; ++i)
		if (line[i] % 2 != 0) {
			printf("-1");
			return 0;
		}

	// start from 1 using dfs
	dfs(0);

	return 0;
}