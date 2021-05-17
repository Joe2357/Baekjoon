#include <stdio.h>

#define MAX_IDX 20
#define INF (int)(2e9 + 1)

int n;
int matrix[MAX_IDX][MAX_IDX];
int dp[MAX_IDX][1 << MAX_IDX];

#define min(a, b) (((a) > (b)) ? (b) : (a))
int func(int did, int used) {
	if (did == n) {
		return 0;
	}
	else if (dp[did][used] != 0) {
		return dp[did][used];
	}
	else {
		int temp = INF;
		for (int i = 0; i < n; ++i) {
			if ((used & (1 << i)) == 0) {
				temp = min(temp, func(did + 1, used | (1 << i)) + matrix[did][i]);
			}
		}
		return dp[did][used] = temp;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &matrix[i][j]);
		}
	}

	printf("%d", func(0, 0));
	return 0;
}