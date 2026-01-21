#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 100
const int NONE = -1;

char str[MAX_LEN + 1];
bool used[MAX_LEN + 1];

void printString() {
	for (int i = 0; str[i] != '\0'; ++i) {
		if (used[i] == true) {
			printf("%c", str[i]);
		}
	}
	printf("\n");
	return;
}

void solve(int left, int right) {
	if (left >= right) { // 범위가 유효하지 않음
		return;
	}

	int min_index = NONE;
	for (int i = left; i < right; ++i) {
		// 사용할 수 있는 문자를 검사
		if (used[i] == false) {
			if (min_index == NONE || str[i] < str[min_index]) {
				min_index = i;
			}
		}
	}

	if (min_index != NONE) {
		used[min_index] = true; // 사용 처리
		printString();			// 현재 상태 출력

		// 오른쪽과 왼쪽 부분 문자열에 대해 재귀 호출
		solve(min_index + 1, right);
		solve(left, min_index);
	}
	return;
}

int main() {
	scanf("%s", str);
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}

	solve(0, len);
	return 0;
}