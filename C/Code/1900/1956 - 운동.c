#include <stdio.h>

#define MAX_INDEX 400
int matrix[MAX_INDEX][MAX_INDEX];

int main() {
	// init
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			#define INF 987654321
			matrix[i][j] = INF;
	}

	// edge init
	for (; k; k--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		matrix[a - 1][b - 1] = c;
	}

	// floyd algorithm
	for (int a = 0; a < n; ++a)
		for (int b = 0; b < n; ++b)
			for (int c = 0; c < n; ++c)
				#define min(a, b) (((a) > (b)) ? (b) : (a))
				matrix[b][c] = min(matrix[b][c], matrix[b][a] + matrix[a][c]);

	// get result
	int retval = INF;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			retval = min(retval, matrix[i][j] + matrix[j][i]);

	// print result
	retval = (retval == INF) ? -1 : retval;
	printf("%d", retval);
	return 0;
}