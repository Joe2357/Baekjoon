#include <stdio.h>

int main() {
	int n, temp = 2, i = 0;
	scanf("%d", &n);
	while (n >= temp + 6 * i)	// counting
		temp = temp + 6 * i++;	// outside++
	printf("%d", i + 1);
	return 0;
}