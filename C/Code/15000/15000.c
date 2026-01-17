#include <stdio.h>

#define MAX_LEN (int)(1e6)

char str[MAX_LEN + 1];

int main() {
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; ++i) {
		str[i] -= 'a';
		str[i] += 'A';
	}
	printf("%s", str);
	return 0;
}