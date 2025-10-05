#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define LENGTH_OF_ALPHABET 26
const int FIRST_WORD = 0;
const int SECOND_WORD = 1;
#define MAX_WORD 2
#define MAX_LEN 1000

int count[MAX_WORD][LENGTH_OF_ALPHABET];
char str[MAX_LEN + 1];

#define abs(x) (((x) < 0) ? (-(x)) : (x))

int main() {
	// 첫 단어 입력
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; ++i) {
		count[FIRST_WORD][str[i] - 'a'] += 1;
	}

	// 다음 단어 입력
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; ++i) {
		count[SECOND_WORD][str[i] - 'a'] += 1;
	}

	// 결과값 계산 및 출력
	int result = 0;
	for (int i = 0; i < LENGTH_OF_ALPHABET; i++)
		result += abs(count[FIRST_WORD][i] - count[SECOND_WORD][i]);
	printf("%d", result);
	return 0;
}