#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define M 100
const int INF = 987654321;

int n, m, r;
int arr[M + 1];
int matrix[M + 1][M + 1];

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
	scanf("%d %d %d", &n, &m, &r);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", arr + i);
		for (int j = 1; j <= n; ++j) {
			matrix[i][j] = INF * (i != j);
		}
	}

	while (r--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		matrix[a][b] = min(matrix[a][b], c);
		matrix[b][a] = min(matrix[b][a], c);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k]);
			}
		}
	}

	int ret = -1;
	for (int i = 1; i <= n; ++i) {
		int tempRet = 0;
		for (int j = 1; j <= n; ++j) {
			tempRet += (arr[j] * (matrix[i][j] <= m));
		}
		ret = max(ret, tempRet);
	}

	printf("%d", ret);
	return 0;
}