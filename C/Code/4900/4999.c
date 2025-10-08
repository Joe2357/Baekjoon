#include <stdio.h>

#define MAX_LEN 1000

char str[MAX_LEN + 1];

int main() {
	int len_1, len_2;

	scanf("%s", str);
	for (len_1 = 0; str[len_1] != '\0'; ++len_1) {
	}
	scanf("%s", str);
	for (len_2 = 0; str[len_2] != '\0'; ++len_2) {
	}

	printf("%s", (len_1 >= len_2) ? "go" : "no");
	return 0;
}