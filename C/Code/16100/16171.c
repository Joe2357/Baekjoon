#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_LEN 100

char s[MAX_LEN * 2];
char k[MAX_LEN * 2];

int main() {
	scanf("%s %s", s, k);

	int l_s = 0;
	for (int i = 0; s[i] != '\0'; ++i) {
		if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')) {
			s[l_s++] = s[i];
		}
	}
	s[l_s] = '\0';

	int l_k = 0;
	for (l_k = 0; k[l_k] != '\0'; ++l_k) {
	}

	bool isAnswerExists = false;
	if (l_s >= l_k) {
		for (int i = 0; s[i] != '\0'; ++i) {
			bool isSame = true;
			for (int j = 0; j < l_k; ++j) {
				isSame &= (s[i + j] == k[j]);
			}
			isAnswerExists |= isSame;
		}
	}

	printf("%d", (isAnswerExists == true));
	return 0;
}