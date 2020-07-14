#include <stdio.h>

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int n;
		char str[21];
		scanf("%d %s", &n, str);
		for (int i = 0; str[i]; i++)        // for all characters
			for (int a = 0; a < n; a++)     // loop n times
				printf("%c", str[i]);
		printf("\n");
	}
	return 0;
}