#include <stdio.h>

int main() {
	char str[3 + 1];
	scanf("%s", str);
	printf("%c%c%c", str[2], str[1], str[0]);
	return 0;
}