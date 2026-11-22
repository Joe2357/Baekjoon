#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN (int)(2e5)

char s[MAX_LEN + 1], k[MAX_LEN + 1];
int l_s, l_k;
int pi[MAX_LEN + 1];

void remove_number(char* st) {
	int idx = 0;
	for (int i = 0; st[i] != '\0'; ++i) {
		if ('a' <= st[i] && st[i] <= 'z' || 'A' <= st[i] && st[i] <= 'Z') {
			st[idx++] = st[i];
		}
	}
	st[idx] = '\0';
	l_s = idx;
	return;
}

void getPi(char* st) {
	int i, j;
	for (i = 1, j = 0; st[i] != '\0'; ++i) {
		// 찾는 글자가 다른 경우
		while (j > 0 && st[i] != st[j]) {
			j = pi[j - 1]; // 접두사와 접미사가 같았다는 정보를 활용
		}

		// 찾는 글자가 같은 경우
		if (st[i] == st[j]) {
			pi[i] = ++j;
		}
	}
	l_k = i;
	return;
}

int main() {
	scanf("%s", s);
	remove_number(s);
	scanf("%s", k);

	// kmp 알고리즘 시작
	bool isAnswerExists = false;
	getPi(k);
	for (int i = 0, j = 0; i < l_s; ++i) {
		// 탐색 문자가 다른 경우
		while (j > 0 && s[i] != k[j]) {
			j = pi[j - 1];
		}

		// 탐색 문자가 같은 경우
		if (s[i] == k[j]) {
			if (j == l_k - 1) {
				isAnswerExists = true;
				break;
			} else {
				j += 1;
			}
		}
	}
	printf("%d", (isAnswerExists == true));
	return 0;
}