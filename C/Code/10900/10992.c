#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	for (int a = 0; a < n - 1; a++) {
		printf(" ");
	}
	printf("*\n");

	if (n == 1) {
		return 0;
	}

	for (int a = 1; a < n - 1; a++) {
		for (int i = n - a - 1; i; i--) {
			printf(" ");
		}
		printf("*");
		for (int i = 0; i < 2 * a - 1; i++) {
			printf(" ");
		}
		printf("*\n");
	}
	for (int a = 0; a < 2 * n - 1; a++) {
		printf("*");
	}
	return 0;
}