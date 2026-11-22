#include <stdbool.h>
#include <stdio.h>

#define MAX_LEN (int)(5e5)

char str[MAX_LEN + 1];
int len;

bool isAllSameCharacter() {
	for (int i = 1; i < len; ++i) {
		if (str[i] != str[0]) {
			return false;
		}
	}
	return true;
}

bool isPalindrome() {
	for (int i = 0, j = len - 1; i < j; ++i, --j) {
		if (str[i] != str[j]) {
			return false;
		}
	}
	return true;
}

int main() {
	scanf("%s", str);

	// 문자열의 길이 먼저 구하기
	for (len = 0; str[len] != '\0'; ++len) {
	}

	if (isAllSameCharacter() == true) { // 문자열의 모든 문자가 같다면 회문이 아닌 경우가 없음
		printf("-1");
	} else if (isPalindrome() == true) { // 전체 문자열이 팰린드롬이면, 문자 1개만 빼주면 팰린드롬이 아님
		printf("%d", len - 1);
	} else { // 전체가 팰린드롬이 아니므로 그 자체로 답이 됨
		printf("%d", len);
	}

	return 0;
}