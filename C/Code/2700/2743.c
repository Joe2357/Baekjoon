#include <stdio.h>

#define MAX_LEN 100

char str[MAX_LEN + 1];

int main() {
	scanf("%s", str);

	int len;
	for (len = 0; str[len] != '\0'; ++len) {
	}
	printf("%d", len);
	return 0;
}