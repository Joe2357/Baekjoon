#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define ALPHABET 26
#define MAX_LEN 100
bool blacklist[ALPHABET + 1];
char str[MAX_LEN + 1];
const char* forbidden_string = "CAMBRIDGE";

void init() {
	for (int i = 0; forbidden_string[i] != '\0'; ++i) {
		blacklist[forbidden_string[i] - 'A'] = true;
	}
	return;
}

int main() {
	init();
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; ++i) {
		if (blacklist[str[i] - 'A'] == false) {
			printf("%c", str[i]);
		}
	}
	return 0;
}