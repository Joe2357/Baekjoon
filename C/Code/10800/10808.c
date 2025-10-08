#include <stdio.h>

#define MAX_LEN 100
#define MAX_ALPHABET 26

char str[MAX_LEN + 1];
int alphabet_count[MAX_ALPHABET];

int main() {
	scanf("%s", str);

	for (int i = 0; str[i] != '\0'; ++i) {
		alphabet_count[str[i] - 'a'] += 1;
	}
	for (int i = 0; i < MAX_ALPHABET; ++i) {
		printf("%d ", alphabet_count[i]);
	}
	return 0;
}