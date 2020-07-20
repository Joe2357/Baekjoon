#include <stdio.h>
#define min(a, b) ((a) > (b)) ? (b) : (a)
#define INF 1000000000
#define MAX_INDEX 500

typedef struct File {
	int cost, sum;
} FL;

int main(t) {
	// loop testcase
	for (scanf("%d", &t); t; t--) {
		// init
		FL dp[MAX_INDEX][MAX_INDEX];
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dp[i][j] = (FL) { INF, INF };

		// loop
		for (int i = 0; i < n; i++) { // file number
			scanf("%d", &dp[i][i].cost);
			dp[i][i].sum = 0;

			// update dp value
			for (int a = i - 1; a >= 0; a--)
				for (int b = a; b < i; b++)
					// update dp value
					if (dp[a][b].sum + dp[b + 1][i].sum + dp[a][b].cost + dp[b + 1][i].cost < dp[a][i].sum)
						dp[a][i].cost = dp[a][b].cost + dp[b + 1][i].cost,
						dp[a][i].sum = dp[a][b].sum + dp[b + 1][i].sum + dp[a][i].cost;
		}

		// print result
		printf("%d\n", dp[0][n - 1].sum);
	}
	return 0;
}