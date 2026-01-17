#include <stdio.h>

#define MAX_IDX (int)(1e7)
const int MOD = 10;

int dp[MAX_IDX + 1];
int n;

void init() {
	dp[n - 1] = 0;
	dp[n - 2] = 2;
	dp[n - 3] = 3;
	return;
}

int main() {
	scanf("%d", &n);

	if (n == 1) {
		printf("0");
	} else if (n == 2) {
		printf("2");
	} else if (n == 3) {
		printf("3");
	} else {
		init();
		for (int i = n - 4; i >= 0; --i) {
			dp[i] = (dp[i + 1] + dp[i + 2]) % MOD;
		}
		printf("%d", dp[0]);
	}
	return 0;
}