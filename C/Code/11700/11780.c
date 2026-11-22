#include <stdio.h>

#define MAX_CITY 100
#define INF (int)1e9
#define NO_PATH -2
#define DIRECT -1

int matrix[MAX_CITY][MAX_CITY];
int transfer[MAX_CITY][MAX_CITY];
int path[MAX_CITY]; int top;

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define FOR(a, b) for(a=0;a<b;++a)

void findPath(int start, int end) {
	if (transfer[start][end] == DIRECT) {
		path[top++] = start;
		path[top++] = end;
	}
	else {
		findPath(start, transfer[start][end]);
		--top;
		findPath(transfer[start][end], end);
	}
	return;
}

int main() {
	/* 도시개수 입력 */
	int n;
	scanf("%d", &n);

	/* 임시변수 선언 */
	int i, j, k;

	/* initialize */
	FOR(i, n) {
		FOR(j, n) {
			matrix[i][j] = INF;
			transfer[i][j] = NO_PATH;
		}
	}

	/* 간선 입력 */
	int m;
	for (scanf("%d", &m); m; --m) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		--a; --b;
		if (matrix[a][b] > c) {
			matrix[a][b] = c, transfer[a][b] = DIRECT;
		}
	}

	/* 플로이드 알고리즘 실행 */
	FOR(k, n) {
		FOR(i, n) {
			FOR(j, n) {
				if (i == j) continue;
				if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
					matrix[i][j] = matrix[i][k] + matrix[k][j];
					transfer[i][j] = k;
				}
			}
		}
	}

	/*
	FOR(i, n) {
		matrix[i][i] = INF;
		transfer[i][i] = NO_PATH;
	}
	*/

	FOR(i, n) {
		FOR(j, n) {
			printf("%d ", ((matrix[i][j] == INF) ? 0 : matrix[i][j]));
		}
		printf("\n");
	}

	FOR(i, n) {
		FOR(j, n) {
			if (transfer[i][j] == NO_PATH) {
				printf("0\n");
			}
			else if (transfer[i][j] == DIRECT) {
				printf("2 %d %d\n", i + 1, j + 1);
			}
			else {
				top = 0;
				findPath(i, j);
				printf("%d ", top);
				FOR(k, top) {
					printf("%d ", path[k] + 1);
				}
				printf("\n");
			}
		}
	}

	return 0;
}