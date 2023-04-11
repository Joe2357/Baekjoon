#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define ALPHABET ('z' - 'a' + 1)
bool isBowel[ALPHABET];
bool canUse[ALPHABET];

#define MAX_LEN (15 + 1)
char code[MAX_LEN];
int bowelUsed;
int l, c;

#define getIndex(x) (x - 'a')

void back(int len, int cur) {
	if (len == l) {
		if (1 <= bowelUsed && bowelUsed <= (l - 2)) {
			printf("%s\n", code);
		}
		return;
	}

	for (int i = cur; i < 'z' - 'a' + 1; ++i) {
		if (canUse[i] == true) {
			code[len] = i + 'a';
			canUse[i] = false;
			if (isBowel[i] == true) {
				++bowelUsed;
			}

			back(len + 1, i + 1);

			canUse[i] = true;
			if (isBowel[i] == true) {
				--bowelUsed;
			}
		}
	}

	return;
}

int main() {
	scanf("%d %d", &l, &c);
	code[l] = '\0';
	while (c--) {
		char input[3];
		scanf("%s", input);
		canUse[getIndex(input[0])] = true;
	}
	isBowel[getIndex('a')] = true;
	isBowel[getIndex('e')] = true;
	isBowel[getIndex('i')] = true;
	isBowel[getIndex('o')] = true;
	isBowel[getIndex('u')] = true;

	back(0, 0);

	return 0;
}