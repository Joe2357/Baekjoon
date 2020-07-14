#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int n;
		char str[81];
		scanf("%d %s", &n, str);
		for (int i = 0; str[i]; i++)
			if (n - i - 1)                  // don't print n'th character
				printf("%c", str[i]);
		printf("\n");
	}
	return 0;
}