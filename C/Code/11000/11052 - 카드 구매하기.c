#include <stdio.h>
#define max(a, b) (a > b) ? a : b

int main(n) {
	int dp[1001] = { 0 };
	scanf("%d", &n);
	for (int t = 1; t <= n; t++) {
		int a;
		scanf("%d", &a);
		for (int i = t; i <= n; i++)
			dp[i] = max(dp[i], dp[i - t] + a);
	}
	printf("%d", dp[n]);
	return 0;
}