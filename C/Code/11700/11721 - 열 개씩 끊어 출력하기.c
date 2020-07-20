#include <stdio.h>

int main() {
	// init
	char str[101];
	scanf("%s", str);

	// loop all char
	for (int i = 0; str[i]; i++) {
		if (!(i % 10) && i) // loop every 10
			printf("\n");
		printf("%c", str[i]);
	}
	return 0;
}