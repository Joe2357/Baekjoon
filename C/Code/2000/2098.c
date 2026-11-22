#include <stdio.h>
#define min(a, b) (((a) > (b)) ? (b) : (a))

#define MAX_LEN 16
int matrix[MAX_LEN][MAX_LEN];
int n;
int comp;
int dp[MAX_LEN][1 << MAX_LEN];

#define START 0
#define INF 987654321
int TSP(int cur, int visited) {

	if (dp[cur][visited] > 0) {
		return dp[cur][visited];
	}

	if (visited == comp) {
		if (matrix[cur][START] == 0) {
			return INF;
		} else {
			return matrix[cur][START];
		}
	}

	int temp = INF;
	for (int i = 1; i < n; ++i) {
		if (matrix[cur][i] != 0 && (visited & (1 << i)) == 0) {
			temp = min(temp, TSP(i, (visited | (1 << i))) + matrix[cur][i]);
		}
	}

	dp[cur][visited] = temp;
	return temp;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &matrix[i][j]);
		}
	}

	comp = (1 << n) - 1;

	printf("%d", TSP(START, 1));
	return 0;
}