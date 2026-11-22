#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", 1 + (n % 2 == 0));
	return 0;
}