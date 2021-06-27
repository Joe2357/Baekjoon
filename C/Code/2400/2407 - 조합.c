#include <stdio.h>

typedef struct Node {
	long long a, b;
} ND;

#define P (long long)1e17
#define MAX_IDX 100 + 1

ND dp[MAX_IDX][MAX_IDX];
int a, b;

int main() {
	scanf("%d %d", &a, &b);
	if (b > a - b) {
		b = a - b;
	}

	dp[1][0] = (ND) { 0, 1 }, dp[1][1] = (ND) { 0, 1 };

	for (int i = 2; i <= a; ++i) {
		dp[i][0] = (ND) { 0, 1 };
		for (int j = 1; j <= b; ++j) {
			dp[i][j] = (ND) { dp[i - 1][j - 1].a + dp[i - 1][j].a, dp[i - 1][j - 1].b + dp[i - 1][j].b };
			if (dp[i][j].b >= P) {
				++dp[i][j].a, dp[i][j].b -= P;
			}
		}
	}

	if (dp[a][b].a == 0) {
		printf("%lld", dp[a][b].b);
	}
	else {
		printf("%lld%016lld", dp[a][b].a, dp[a][b].b);
	}
	return 0;
}