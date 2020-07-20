#include <stdio.h>

int main(n) {
	// init
	char str[101];
	scanf("%d %s", &n, str);

	// loop all char
	int sum = 0;
	for (int i = 0; str[i]; i++)
		sum += (str[i] - '0');

	// print result
	printf("%d", sum);
	return 0;
}