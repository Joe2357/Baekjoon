#include <stdio.h>

int main() {
	char str[1001];
	scanf("%s", str);
	int x;
	scanf("%d", &x);
	printf("%c", str[x - 1]);
	return 0;
}