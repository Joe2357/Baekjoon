#include <stdio.h>

#define MAX_LEN 1000 + 1

int dp[MAX_LEN][MAX_LEN];
char str[2][MAX_LEN];
int len[2];

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))
int main() {
	scanf("%s %s", str[0], str[1]);

	for (len[0] = 0; str[0][len[0]]; ++len[0]);
	for (len[1] = 0; str[1][len[1]]; ++len[1]);

	for (int i = 1; i <= len[0]; ++i) {
		for (int j = 1; j <= len[1]; ++j) {
			if (str[0][i - 1] == str[1][j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	int r = dp[len[0]][len[1]];
	printf("%d\n", r);
	str[0][r] = '\0';
	for (int a = len[0], b = len[1]; r > 0;) {
		if (dp[a - 1][b] == dp[a][b]) {
			--a;
		}
		else if (dp[a][b - 1] == dp[a][b]) {
			--b;
		}
		else if (dp[a - 1][b - 1] + 1 == dp[a][b]) {
			str[0][--r] = str[1][b - 1];
			--a, --b;
		}
	}
	printf("%s", str[0]);
	return 0;
}