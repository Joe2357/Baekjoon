#include <stdio.h>

#define MAX_LEN 100
const int NEWLINE_POINT = 10;

int main() {
	char str[MAX_LEN + 1];
	scanf("%s", str);

	// loop all char
	for (int i = 0; str[i] != '\0'; ++i) {
		printf("%c", str[i]);
		if (i % NEWLINE_POINT == NEWLINE_POINT - 1) {
			printf("\n");
		}
	}
	return 0;
}