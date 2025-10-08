#include <stdio.h>

#define MAX_IDX (int)(1e5)
const int INF = 987654321;

int dp[MAX_IDX + 1];

#define min(a, b) (((a) > (b)) ? (b) : (a))

void init() {
	for (int i = 0; i <= MAX_IDX; ++i) {
		dp[i] = INF;
	}
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 1; i * i <= MAX_IDX; ++i) {
		for (int j = i * i; j <= MAX_IDX; ++j) {
			dp[j] = min(dp[j], dp[j - (i * i)] + 1);
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