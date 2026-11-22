#include <stdio.h>

#define M_S 101
#define INF 987654321
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))
int bigger[M_S][M_S], smaller[M_S][M_S];
int n, m;

void init() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			bigger[i][j] = smaller[i][j] = (INF * (i != j));
		}
	}
	return;
}

int main() {
	scanf("%d %d", &n, &m);
	init();
	for (; m; --m) {
		int a, b;
		scanf("%d %d", &a, &b);
		bigger[b][a] = 1, smaller[a][b] = 1;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				bigger[j][k] = min(bigger[j][k], bigger[j][i] + bigger[i][k]);
				smaller[j][k] = min(smaller[j][k], smaller[j][i] + smaller[i][k]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		int a = 0;
		for (int j = 1; j <= n; ++j) {
			a += (bigger[i][j] == INF && smaller[i][j] == INF);
		}
		printf("%d\n", a);
	}

	return 0;
}