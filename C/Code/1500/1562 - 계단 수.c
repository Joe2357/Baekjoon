#include <stdio.h>

#define DIGIT 10
const int MOD = (int)(1e9);

int dp[1 << DIGIT][DIGIT];
int batch[1 << DIGIT][DIGIT];

int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i < DIGIT; ++i) {
		dp[1 << i][i] = 1;
	}

	long long tempRetval = 0;
	for (int t = 2; t <= n; ++t) {
		for (int i = 0; i < (1 << DIGIT); ++i) {
			for (int j = 0; j < DIGIT; ++j) {
				batch[i][j] = dp[i][j];
				dp[i][j] = 0;
			}
		}

		for (int i = 0; i < (1 << DIGIT); ++i) {
			for (int j = 0; j < DIGIT; ++j) {
				if (j > 0) {
					dp[i | (1 << (j - 1))][j - 1] += batch[i][j];
					dp[i | (1 << (j - 1))][j - 1] %= MOD;
				}
				if (j < 9) {
					dp[i | (1 << (j + 1))][j + 1] += batch[i][j];
					dp[i | (1 << (j + 1))][j + 1] %= MOD;
				}
			}
		}
	}

	int retval = 0;
	for (int i = 0; i < DIGIT; ++i) {
		retval = (retval + dp[(1 << DIGIT) - 1][i]) % MOD;
	}
	printf("%d", retval);

	return 0;
}