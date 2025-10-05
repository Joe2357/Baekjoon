#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define ALPHABET 26
#define MAX_LEN 200

char str[MAX_LEN + 1];
bool used[ALPHABET + 1];

void init() {
	for (int i = 0; i < ALPHABET; ++i) {
		used[i] = false;
	}
	return;
}

int main() {
	do {
		init();
		gets(str);
		if (str[0] == '*') {
			break;
		}

		for (int i = 0; str[i] != '\0'; ++i) {
			if ('a' <= str[i] && str[i] <= 'z') {
				used[str[i] - 'a'] = true;
			}
		}

		bool ispangram = true;
		for (int i = 0; i < ALPHABET; ++i) {
			ispangram &= used[i];
		}

		printf("%c\n", (ispangram == true) ? 'Y' : 'N');
	} while (true);
	return 0;
}