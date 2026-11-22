#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define M 501 + 1
const int INF = 987654321;

int matrix[M][M];
int dist[M];
int n, m, w;

#define min(a, b) (((a) > (b)) ? (b) : (a))
void init() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			matrix[i][j] = INF * (i != j);
		}
		matrix[i][n + 1] = matrix[n + 1][i] = 0;
		dist[i] = 0;
	}
	matrix[n + 1][n + 1] = 0;
	dist[n + 1] = 0;
	return;
}

bool bellman_ford() {
	bool ret = false;
	for (int i = 1; i <= n; ++i) {
		if (dist[i] != INF) {
			for (int j = 1; j <= n; ++j) {
				if (dist[j] > dist[i] + matrix[i][j]) {
					dist[j] = dist[i] + matrix[i][j];
					ret = true;
				}
			}
		}
	}
	return ret;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d", &n, &m, &w);
		init();

		while (m--) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			matrix[a][b] = matrix[b][a] = min(matrix[a][b], c);
		}

		while (w--) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			matrix[a][b] = min(matrix[a][b], -c);
		}

		bool isChanged = true;
		int count = n;
		while (isChanged && count) {
			isChanged = bellman_ford();
			--count;
		}

		printf("%s\n", (bellman_ford() ? "YES" : "NO"));
	}

	return 0;
}