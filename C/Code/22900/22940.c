#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 6
#define NONE -1

double matrix[MAX_IDX][MAX_IDX + 1];
int rowIndex[MAX_IDX];
bool visit[MAX_IDX + 1];
int n;

#define abs(x) (((x) < 0) ? (-(x)) : (x))

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		rowIndex[i] = NONE;
		visit[i] = false;
		for (int j = 0; j <= n; ++j) {
			scanf("%lf", &matrix[i][j]);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (visit[j] == true) {
				continue;
			} else if (rowIndex[i] == NONE ||
					   (matrix[j][i] != 0 &&
						abs(matrix[j][i]) < abs(matrix[rowIndex[i]][i]))) {
				rowIndex[i] = j;
			}
		}
		visit[rowIndex[i]] = true;
		double temp = matrix[rowIndex[i]][i];
		for (int a = 0; a <= n; ++a) {
			matrix[rowIndex[i]][a] /= temp;
		}

		for (int a = 0; a < n; ++a) {
			if (rowIndex[i] == a) {
				continue;
			}
			double temp = matrix[a][i];
			for (int b = 0; b <= n; ++b) {
				matrix[a][b] -= (temp * matrix[rowIndex[i]][b]);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%.0lf ", matrix[rowIndex[i]][n]);
	}
	return 0;
}