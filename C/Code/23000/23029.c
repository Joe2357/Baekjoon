#include <stdio.h>

#define MAX_IDX (int)(1e5)

int dp[MAX_IDX + 1][3];
int arr[MAX_IDX + 1];
int n;

#define max(a, b) ((a) > (b) ? (a) : (b))

void read_input() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &arr[i]);
	}
	return;
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
		dp[i][1] = dp[i - 1][0] + arr[i];
		dp[i][2] = dp[i - 1][1] + (arr[i] / 2);
	}
	return;
}

int main() {
	read_input();
	solve();
	printf("%d", max(dp[n][0], max(dp[n][1], dp[n][2])));
	return 0;
}