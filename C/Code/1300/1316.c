#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define MAX_ALPHABET 26
#define MAX_LEN 100

char str[MAX_LEN + 1];

bool isGroupWord(const char* s) {
	bool appeared[MAX_ALPHABET + 1] = {
		false,
	};

	char prev = '\0';
	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i] != prev) {
			if (appeared[s[i] - 'a']) {
				return false;
			}
			appeared[s[i] - 'a'] = true;
			prev = s[i];
		}
	}
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	int ret = 0;
	while (n--) {
		scanf("%s", str);
		ret += isGroupWord(str);
	}
	printf("%d", ret);
	return 0;
}