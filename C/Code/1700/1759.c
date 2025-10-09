#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define ALPHABET ('z' + 2)
bool isVowel[ALPHABET];
bool canUse[ALPHABET];

#define MAX_LEN 15
char code[MAX_LEN + 1];
int vowelUsed;
int l, c;

void dfs(int len, int cur) {
	if (len == l) {
		if (1 <= vowelUsed && vowelUsed <= (l - 2)) {
			printf("%s\n", code);
		}
		return;
	}

	for (int i = cur; i <= 'z'; ++i) {
		if (canUse[i] == true) {
			code[len] = i;

			canUse[i] = false;
			vowelUsed += (isVowel[i] == true);

			dfs(len + 1, i + 1);

			canUse[i] = true;
			vowelUsed -= (isVowel[i] == true);
		}
	}
	return;
}

void vowel_init(char* str) {
	for (int i = 0; str[i] != '\0'; ++i) {
		isVowel[str[i]] = true;
	}
	return;
}

int main() {
	scanf("%d %d", &l, &c);
	code[l] = '\0';
	while (c--) {
		char input[3];
		scanf("%s", input);
		canUse[input[0]] = true;
	}

	vowel_init("aeiou");
	dfs(0, 'a');
	return 0;
}