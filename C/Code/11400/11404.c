#include <stdio.h>
#define min(a, b) (((a) > (b)) ? (b) : (a))

#define M_I 101
#define INF 987654321
int matrix[M_I][M_I];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			matrix[i][j] = INF * (i != j);
		}
	}

	int m;
	scanf("%d", &m);
	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		matrix[a][b] = min(matrix[a][b], c);
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			printf("%d ", matrix[i][j] * (matrix[i][j] != INF));
		}
		printf("\n");
	}

	return 0;
}