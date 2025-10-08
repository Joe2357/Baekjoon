#include <stdio.h>
#define max(a, b) ((a > b) ? (a) : (b))

int main(n) {
	int dp[17] = {0};
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int day, cost;
		scanf("%d %d", &day, &cost);
		if (i + day <= n + 1)
			dp[i + day] = max(dp[i + day], dp[i] + cost);
		for (int a = i + day; a <= n + 1; a++)
			dp[a] = max(dp[a], dp[i + day]);
	}
	printf("%d", dp[n + 1]);
	return 0;
}