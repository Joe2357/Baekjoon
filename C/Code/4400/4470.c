#include <stdio.h>

#define MAX_LEN 50

char str[MAX_LEN + 1];

int main() {
	int n;
	scanf("%d ", &n);
	for (int i = 1; i <= n; ++i) {
		gets(str);
		printf("%d. %s\n", i, str);
	}
	return 0;
}