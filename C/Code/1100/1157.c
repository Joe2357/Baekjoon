#include <stdio.h>

#define MAX_LEN (int)(1e6)
#define MAX_ALPHA 26

char str[MAX_LEN + 1];
int alphabet_count[MAX_ALPHA];

void read_input() {
	scanf("%s", str);
	return;
}

int main() {
	read_input();

	// 문자열의 알파벳 숫자 세기
	for (int i = 0; str[i] != '\0'; ++i) {
		if ('a' <= str[i] && str[i] <= 'z') {
			alphabet_count[str[i] - 'a'] += 1;
		} else if ('A' <= str[i] && str[i] <= 'Z') {
			alphabet_count[str[i] - 'A'] += 1;
		}
	}

	// 1차 : 알파벳이 가장 많이 나온 '갯수' 세기
	int ret = 0;
	for (int i = 0; i < MAX_ALPHA; ++i) {
		if (alphabet_count[i] > alphabet_count[ret]) {
			ret = i;
		}
	}

	// 2차 : 가장 많이 나온 알파벳이 무엇인지 확인
	// 만약 이미 선택된 ret가 아니라면, 2개 이상 있는 것이므로 '?' 출력
	for (int i = 0; i < MAX_ALPHA; ++i) {
		if (alphabet_count[i] == alphabet_count[ret] && i != ret) {
			printf("?");
			return 0;
		}
	}

	// 3차 : '?' 출력이 안되었다면 이전에 찾은 결과값 출력
	printf("%c", ret + 'A');
	return 0;
}
