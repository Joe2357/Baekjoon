#include <stdio.h>
#define max(a, b) ((a > b) ? (a) : (b))

int main(n) {
	// init
	int dp[17] = { 0 };
	scanf("%d", &n);

	// check every day
	for (int i = 1; i <= n; i++) {
		int day, cost;
		scanf("%d %d", &day, &cost);
		if (i + day <= n + 1) // put that counsel
			dp[i + day] = max(dp[i + day], dp[i] + cost);
		for (int a = i + day; a <= n + 1; a++) // compare ( put, not put )
			dp[a] = max(dp[a], dp[i + day]);
	}

	// print the biggest value
	printf("%d", dp[n + 1]);
	return 0;
}