#include <stdio.h>

#define MAX_INDEX 20 + 1
int dp[MAX_INDEX][MAX_INDEX][MAX_INDEX];
int a, b, c, d, e, f;

void init() {
	for (int i = 0; i < MAX_INDEX; ++i) {
		for (int j = 0; j < MAX_INDEX; ++j) {
			for (int k = 0; k < MAX_INDEX; ++k) {
				if (i == 0 || j == 0 || k == 0)
					dp[i][j][k] = 1;
				else if (i < j && j < k) {
					dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
				}
				else {
					dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
				}
			}
		}
	}
	return;
}

int main() {
	init();
	#define True 1
	while (True) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == b && b == c && c == -1) {
			break;
		}
		else if (a <= 0 || b <= 0 || c <= 0) {
			d = e = f = 0;
		}
		else if (a > 20 || b > 20 || c > 20) {
			d = e = f = 20;
		}
		else {
			d = a, e = b, f = c;
		}
		printf("w(%d, %d, %d) = %d\n", a, b, c, dp[d][e][f]);
	}
	return 0;
}