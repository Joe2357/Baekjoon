#include <stdio.h>

#define MAX_LEN 100
#define ALPHABET 26
const int NONE = -1;

char str[MAX_LEN + 1];
int index[ALPHABET];

void init() {
	for (int i = 0; i < ALPHABET; ++i) {
		index[i] = NONE;
	}
	return;
}

int main() {
	init();
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; ++i) {
		int temp = str[i] - 'a';
		if (index[temp] == NONE) {
			index[temp] = i;
		}
	}
	for (int i = 0; i < ALPHABET; ++i) {
		printf("%d ", index[i]);
	}
	return 0;
}