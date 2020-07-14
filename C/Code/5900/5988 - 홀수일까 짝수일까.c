#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	char result[2][5] = { "even", "odd" };
	for (int i = 0; i < n; i++) {
		char str[101];
		scanf("%s", str);
		int i;
		for (i = 0; str[i]; i++)
			; // find last word
		printf("%s\n", result[str[--i] % 2]);
	}
	return 0;
}