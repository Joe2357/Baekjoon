#include <stdio.h>

#define MAX_LEN 1000
const int ALPHABET = 26;
const int lshift = 3;

char str[MAX_LEN + 1];

int main() {
	scanf("%s", str);

	for (int i = 0; str[i] != '\0'; ++i) {
		char c = (((str[i] - 'A') + ALPHABET - lshift) % ALPHABET) + 'A';
		printf("%c", c);
	}
	return 0;
}