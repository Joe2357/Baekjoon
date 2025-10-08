#include <stdio.h>

#define MAX_LEN 1000

int main() {
	char str[MAX_LEN + 1];
	scanf("%s", str);

	int i;
	scanf("%d", &i);
	printf("%c", str[i - 1]);
	return 0;
}