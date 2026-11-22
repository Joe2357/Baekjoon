#include <stdbool.h>
#include <stdio.h>

#define MAX_IDX 30

typedef long long ll;

// 이 문제의 정답은 "카탈랑 수"라고 한다.
ll ans[MAX_IDX + 1] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190, 6564120420, 24466267020, 91482563640, 343059613650, 1289904147324, 4861946401452, 18367353072152, 69533550916004, 263747951750360, 1002242216651368, 3814986502092304};
ll dp[MAX_IDX + 1][MAX_IDX + 1]; // dp[i][j] = W를 i번, H를 j번 사용하여 만들 수 있는 문자열의 갯수

void init() {
	dp[0][0] = 1LL;

	for (int i = 0; i <= MAX_IDX; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (i < MAX_IDX) {
				dp[i + 1][j] += dp[i][j];
			}
			if (j < i && j < MAX_IDX) {
				dp[i][j + 1] += dp[i][j];
			}
		}
	}
	return;
}

int main() {
	init();

	while (true) {
		int n;
		scanf("%d", &n);
		if (n == 0) {
			break;
		}

		// printf("%lld\n", ans[n]);
		printf("%lld\n", dp[n][n]);
	}

	return 0;
}