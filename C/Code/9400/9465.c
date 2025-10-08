#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int arr[2][100001],
			dp[3][100001] = {0}, n; // dynamic programming
		scanf("%d", &n);
		for (int a = 0; a < 2; a++) // get all price of sticker
			for (int i = 1; i <= n; i++)
				scanf("%d", &arr[a][i]);
		dp[0][1] = arr[0][1], dp[1][1] = arr[1][1],
		dp[2][1] = max(dp[0][1], dp[1][1]);								// dp first init
		for (int i = 2; i <= n; i++)									// dp starts
			dp[0][i] = max(dp[2][i - 2], dp[1][i - 1]) + arr[0][i],		// 0 :: no continuous
				dp[1][i] = max(dp[2][i - 2], dp[0][i - 1]) + arr[1][i], // 1 :: 1 continuous
				dp[2][i] = max(dp[0][i], dp[1][i]);						// the biggest value in two values
		printf("%d\n", dp[2][n]);										// print result
	}
	return 0;
}