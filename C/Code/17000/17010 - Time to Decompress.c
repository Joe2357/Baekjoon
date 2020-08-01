#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int n;
		char c;
		for (scanf("%d %c", &n, &c); n; n--)
			printf("%c", c);
		printf("\n");
	}
	return 0;
}