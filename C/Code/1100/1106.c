#include <stdio.h>

#define MAX_CUSTOMER 1000
const int INF = 987654321;

int dp[MAX_CUSTOMER + 1];
int c, n;

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))

void init() {
	dp[0] = 0;
	for (int i = 1; i <= MAX_CUSTOMER; ++i) {
		dp[i] = INF;
	}
	return;
}

int main() {
	init();
	scanf("%d %d", &c, &n);

	for (int i = 0; i < n; ++i) {
		int cost, customer;
		scanf("%d %d", &cost, &customer);

		for (int i = customer; i <= c; ++i) {
			dp[i] = min(dp[i], dp[i - customer] + cost);
		}
		for (int i = max(c - customer, 0); i <= c; ++i) {
			dp[c] = min(dp[c], dp[i] + cost);
		}
	}

	printf("%d", dp[c]);
	return 0;
}