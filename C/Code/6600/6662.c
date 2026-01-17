#include <stdio.h>

#define MAX_VAL 431

int dp[MAX_VAL + 1][MAX_VAL + 1];

void init() {
	for (int i = 2; i <= MAX_VAL; ++i) {
		int x = i;
		for (int j = 2; j <= i; ++j) {
			dp[i][j] = dp[i - 1][j];
			while (x % j == 0) {
				dp[i][j]++;
				x /= j;
			}
		}
	}
	return;
}

long long solve(int n, int k) {
	long long result = 1;
	for (int i = 2; i <= n; ++i) {
		if (dp[n][i] > 0) {
			int count = dp[n][i] - dp[k][i] - dp[n - k][i];
			result *= (count + 1);
		}
	}
	return result;
}

int main() {
	init();
	int n, k;

	while (scanf("%d %d", &n, &k) != EOF) {
		printf("%lld\n", solve(n, k));
	}
	return 0;
}