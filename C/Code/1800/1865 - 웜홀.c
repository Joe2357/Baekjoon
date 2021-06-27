#include <stdio.h>

#define True 1
#define False 0
typedef char boolean;

#define MAX_IDX (500 + 1)
#define INF 987654321

#define min(a, b) (((a) > (b)) ? (b) : (a))

int main(t) {
	scanf("%d", &t);
	while (t--) {
		int n, m, w;
		scanf("%d %d %d", &n, &m, &w);
		int matrix[MAX_IDX][MAX_IDX];
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				matrix[i][j] = INF;
			}
		}
		while (m--) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			matrix[a][b] = min(matrix[a][b], c),
			matrix[b][a] = min(matrix[b][a], c);
		}
		while (w--) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			matrix[a][b] = min(matrix[a][b], -c);
		}

		int path[MAX_IDX];
		for (int i = 1; i <= n; ++i) {
			path[i] = INF * (i != n);  // ?
		}

		boolean isChanged = True;
		for (int i = 0; i < n && isChanged; ++i) {
			isChanged = False;

			for (int j = 1; j <= n; ++j) {
				for (int k = 1; k <= n; ++k) {
					if (matrix[j][k] < INF) {
						if (path[j] < INF && path[j] + matrix[j][k] < path[k]) {
							path[k] = path[j] + matrix[j][k];
							isChanged = True;
						}
					}
				}
			}
		}

		printf("%s\n", (isChanged ? "YES" : "NO"));
	}
	return 0;
}