#include <stdio.h>

#define First 0
#define Second 1

#define MAX_IDX 1001
char str[2][MAX_IDX + 1];
int len[2];
int dp[MAX_IDX + 1][MAX_IDX + 1];

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
	scanf("%s %s", &str[First][1], &str[Second][1]);
	str[First][0] = str[Second][0] = '0';

	for (len[First] = 0; str[First][len[First]] != '\0'; ++len[First]) {
	}
	for (len[Second] = 0; str[Second][len[Second]] != '\0'; ++len[Second]) {
	}

	for (int i = 1; i <= len[First]; ++i) {
		for (int j = 1; j <= len[Second]; ++j) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (str[First][i] == str[Second][j]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
	}
	printf("%d", dp[len[First] - 1][len[Second] - 1]);
	return 0;
}