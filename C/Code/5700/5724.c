#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 100

int dp[MAX_IDX + 1];

void init() {
	dp[0] = 0, dp[1] = 1;
	for (int i = 2; i <= MAX_IDX; ++i) {
		dp[i] = dp[i - 1] + (i * i);
	}
	return;
}

int main() {
	init();

	while (true) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			break;
		} else {
			printf("%d\n", dp[x]);
		}
	}

	return 0;
}