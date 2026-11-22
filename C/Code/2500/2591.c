#include <stdio.h>

#define MAX_LEN 40
const int MAX_VALUE = 34;

char str[MAX_LEN + 1];
int dp[MAX_LEN + 1 + 1]; // dp[i] = i번째 idx로부터 끝까지 사용할 때의 경우의 수

int main() {
	int l;
	scanf("%s", str);
	for (l = 0; str[l] != '\0'; ++l) {
	}

	dp[l] = 1; // 완료 상태
	for (int i = l - 1; i >= 0; --i) {
		if (str[i] == '0') { // 0으로 시작하는 경우는 불가능
			dp[i] = 0;
		} else {
			dp[i] = dp[i + 1];
			if (i + 1 < l) {										// 다음 글자가 존재하며,
				int num = (str[i] - '0') * 10 + (str[i + 1] - '0'); // 2자리 수를 만들어 보았을 때,
				if (num <= MAX_VALUE) {								// 만든 숫자가 34 이하라면
					dp[i] += dp[i + 2];								// 이 값도 더해준다
				}
			}
		}
	}

	printf("%d", dp[0]);
	return 0;
}