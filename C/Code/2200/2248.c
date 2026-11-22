#include <stdio.h>

typedef long long ll;

#define MAX_IDX 31
int n, l;
ll i;

ll dp[MAX_IDX + 1][MAX_IDX + 1]; // dp[i][j] = i번째 index가 최고일 때, 그 뒤를 j개의 bit 이하로 구성하여 만들 수 있는 수의 갯수

void init() {
	for (int i = 0; i <= MAX_IDX; ++i) {
		dp[0][i] = 1; // 문자열을 만들 수 없음
	}
	for (int i = 1; i <= MAX_IDX; ++i) {
		dp[i][0] = 1; // 0만 만들 수 있음
		for (int j = 1; j <= MAX_IDX; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
	return;
}

void solve(int n, int l, long long i) {
	if (n == 0) {
		return;
	}

	if (l > 0 && i > dp[n - 1][l]) {
		printf("1");
		solve(n - 1, l - 1, i - dp[n - 1][l]);
	} else {
		printf("0");
		solve(n - 1, l, i);
	}
	return;
}

int main() {
	scanf("%d %d %lld", &n, &l, &i);
	init();
	solve(n, l, i);
	return 0;
}