#include <stdio.h>

#define M 4001
#define I 201
const int MOD = (int)1e6;

int dp[I][M];
int t, a, s, b;
int number[I];
int result;

int main() {
	scanf("%d %d %d %d", &t, &a, &s, &b);
	for (int i = 0; i < a; ++i) {
		int temp;
		scanf("%d", &temp);
		++number[temp];
	}

	dp[0][0] = 1;
	for (int i = 1; i < I; ++i) {
		if (number[i] > 0) {  // 숫자가 있는 경우
			for (int j = number[i]; j >= 0; --j) {
				for (int k = M - 1; k >= j; --k) {
					dp[i][k] += dp[i - 1][k - j], dp[i][k] %= MOD;
				}
			}
		} else {
			for (int j = 0; j < M; ++j) {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	for (int i = s; i <= b; ++i) {
		result += dp[I - 1][i], result %= MOD;
	}
	printf("%d", result);
	return 0;
}