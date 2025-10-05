#include <stdio.h>

#define MAX_LEN 50

char str[MAX_LEN + 1];

int main() {
	int n;
	scanf("%d", &n);
	for (int t = 1; t <= n; ++t) {
		scanf("%s", str);
		printf("String #%d\n", t);
		for (int i = 0; str[i] != '\0'; ++i) {
			printf("%c", ((str[i] == 'Z') ? 'A' : str[i] + 1));
		}
		printf("\n\n");
	}
	return 0;
}