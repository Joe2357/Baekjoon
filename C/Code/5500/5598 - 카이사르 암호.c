#include <stdio.h>

int main() {
	char str[1001];
	scanf("%s", str);
	for (int i = 0; str[i]; i++)
		printf("%c", str[i] - 3 + 26 * (str[i] < 'A'));
	return 0;
}