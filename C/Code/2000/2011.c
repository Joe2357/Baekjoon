#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_IDX 5000

char input[MAX_IDX + 1];
int len;
const int MOD = 1000000;
const int NONE = -1;

int dp[MAX_IDX + 1];
bool isAnswerExist;

int main() {
	scanf("%s", input);
	for (len = 0; input[len] != '\0'; ++len) {
	}
	dp[len] = 1;

	isAnswerExist = true;
	for (int i = len - 1; i >= 0; --i) {
		switch (input[i]) {
			case '0': {
				if (i == 0 || input[i - 1] > '2' || input[i - 1] == '0') {
					isAnswerExist = false;
				}
				break;
			}
			case '1': {
				dp[i] += dp[i + 1] + dp[i + 2];
				break;
			}
			case '2': {
				dp[i] += dp[i + 1];
				if ('0' <= input[i + 1] && input[i + 1] <= '6') {
					dp[i] += dp[i + 2];
				}
				break;
			}
			default: {
				dp[i] += dp[i + 1];
				break;
			}
		}
		dp[i] %= MOD;
	}

	printf("%d", (isAnswerExist == true) ? dp[0] : 0);
	return 0;
}