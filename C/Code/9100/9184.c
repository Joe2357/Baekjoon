#include <stdio.h>

int dp[21][21][21];

void init() {
	for (int i = 0; i < 21; ++i) {
		for (int j = 0; j < 21; ++j) {
			for (int k = 0; k < 21; ++k) {
				dp[i][j][k] = -1;
			}
		}
	}

	for (int i = 0; i < 21; ++i) {
		for (int j = 0; j < 21; ++j) {
			for (int k = 0; k < 21; ++k) {
				dp[i][j][k] = w(i, j, k);
			}
		}
	}

	return;
}

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	} else if (a > 20 || b > 20 || c > 20) {
		return w(20, 20, 20);
	}

	if (dp[a][b][c] != -1) {
		return dp[a][b][c];
	}

	if (a < b && b < c) {
		return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	} else {
		return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
}

int main() {

	init();

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	while (a != -1 || b != -1 || c != -1) {
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
		scanf("%d %d %d", &a, &b, &c);
	}

	return 0;
}
