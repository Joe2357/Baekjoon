#include <stdio.h>

#define MAX_IDX (1000 + 1)
const int start = 1;
const int INF = 987654321;

int cost[MAX_IDX];
int dp[MAX_IDX][MAX_IDX];
int end;
int result = INF;

#define min(a, b) (((a) > (b)) ? (b) : (a))

void init(int x) {
	for (int i = 0; i <= x; ++i) {
		for (int j = 0; j <= x; ++j) {
			dp[i][j] = INF;
		}
	}

	dp[start][0] = 0;
	return;
}

int main() {
	scanf("%d", &end);
	for (int i = 1; i <= end; ++i) {
		scanf("%d", cost + i);
	}
	init(end);

	for (int c = 1; c <= end; ++c) {  // jump width
		for (int x = c; x <= end; ++x) {
			dp[x][c] = min(dp[x][c], dp[x - c][c - 1] + cost[x]);
		}

		for (int x = end - c; x > 0; --x) {
			dp[x][c] = min(dp[x][c], dp[x + c][c] + cost[x]);
		}
	}

	for (int i = start; i <= end; ++i) {
		result = min(result, dp[end][i]);
	}
	printf("%d", result);

	return 0;
}