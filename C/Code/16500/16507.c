#include <stdio.h>

#define MAX_IDX 1000

int map[MAX_IDX + 1][MAX_IDX + 1];
int dp[MAX_IDX + 1][MAX_IDX + 1];
int r, c;

void read_input() {
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			scanf("%d", &map[i][j]);
		}
	}
	return;
}

void init() {
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j];
		}
	}
	return;
}

int main() {
	int q;
	scanf("%d %d %d", &r, &c, &q);
	read_input();
	init();

	while (q--) {
		int r1, c1, r2, c2;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		int ret = dp[r2][c2] - dp[r1 - 1][c2] - dp[r2][c1 - 1] + dp[r1 - 1][c1 - 1];
		ret /= (r2 - r1 + 1) * (c2 - c1 + 1);
		printf("%d\n", ret);
	}
	return 0;
}