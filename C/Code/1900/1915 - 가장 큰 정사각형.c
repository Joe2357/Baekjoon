#include <stdio.h>
#define max(a, b) (a > b) ? a : b
#define min(a, b) (a > b) ? b : a
#define MAX_INDEX 1000

int dp[MAX_INDEX][MAX_INDEX],
maxSquare, n, m;

int main() {
	// init
	char str[MAX_INDEX + 1];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		for (int a = 0; a < m; a++)
			if (str[a] == '1') {
				dp[i][a] = 1; // 1x1 square save
				maxSquare = 1;
			}
	}

	// dp
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			// if square and, if has change to be more bigger square
			if (dp[i][j] && dp[i - 1][j - 1]) { // check other side ( up, left )
				int xLength = dp[i - 1][j - 1] + 1, yLength = xLength;
				for (int a = i - 1; a >= i - dp[i - 1][j - 1]; a--)
					if (!dp[a][j]) {
						xLength = i - a;
						break;
					}
				for (int a = j - 1; a >= j - dp[i - 1][j - 1]; a--) {
					if (!dp[i][a]) {
						yLength = j - a;
						break;
					}
				}
				// merge section
				dp[i][j] = min(xLength, yLength);
				maxSquare = max(maxSquare, dp[i][j]);
			}
		}
	}

	printf("%d", maxSquare * maxSquare);
	return 0;
}