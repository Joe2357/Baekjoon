#include <stdio.h>

int main(t, i, a) {
	i = 0, a = 0;
	for (scanf("%d", &t); i++ < t; a = 0) {
		char str[51];
		scanf("%s", str);
		printf("String #%d\n", i);
		while (str[a])
			printf("%c", (str[a++] + 1 - 'A') % 26 + 'A'); // Caesar +1
		printf("\n\n");
	}
	return 0;
}