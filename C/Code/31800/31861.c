#include <stdio.h>

#define ALPHABET 26
#define MAX_IDX 1000
const int MOD = (int)(1e9 + 7);
const int NONE = -1;

int dp[MAX_IDX + 1][ALPHABET];
int n, m;

#define abs(x) ((x) < 0 ? -(x) : (x))

void init() {
	for (int i = 0; i <= MAX_IDX; ++i) {
		for (int j = 0; j < ALPHABET; ++j) {
			dp[i][j] = NONE;
		}
	}
	return;
}

int solve(int idx, int last) {
	if (idx == m) {
		return 1;
	} else if (dp[idx][last] != NONE) {
		return dp[idx][last];
	}

	int ret = 0;
	for (int next = 0; next <= last - n; ++next) {
		ret = (ret + solve(idx + 1, next)) % MOD;
	}
	for (int next = ALPHABET - 1; next >= last + n; --next) {
		ret = (ret + solve(idx + 1, next)) % MOD;
	}

	if (n == 0) {
		ret = (ret - solve(idx + 1, last) + MOD) % MOD;
	}
	return dp[idx][last] = ret;
}

int main() {
	scanf("%d %d", &n, &m);
	init();
	int result = 0;
	for (int first = 0; first < ALPHABET; ++first) {
		result = (result + solve(1, first)) % MOD;
	}
	printf("%d", result);
	return 0;
}