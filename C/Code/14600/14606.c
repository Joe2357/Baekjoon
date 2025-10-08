#include <stdio.h>

#define MAX_IDX 10

int dp[MAX_IDX + 1];

#define max(a, b) (((a) > (b)) ? (a) : (b))

void init() {
	dp[0] = 0;
	dp[1] = 0;
	for (int i = 2; i <= MAX_IDX; ++i) {
		for (int j = 1; j < i; ++j) {
			dp[i] = max(dp[i], dp[j] + dp[i - j] + (j) * (i - j));
		}
	}
	return;
}

int main() {
	init();

	int n;
	scanf("%d", &n);
	printf("%d", dp[n]);
	return 0;
}