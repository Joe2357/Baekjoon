#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {					// n * n square
		for (int j = 0; j < i + 1; j++)
			printf("*");
		for (int j = 0; j < 2 * n - 2 * i - 2; j++)		// blank reverse pyramid
			printf(" ");
		for (int j = 0; j < i + 1; j++)
			printf("*");
		printf("\n");
	}
	for (int i = 0; i < 2 * n; i++)
		printf("*");
	printf("\n");
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++)
			printf("*");
		for (int j = 0; j < 2 * i + 2; j++)
			printf(" ");
		for (int j = 0; j < n - i - 1; j++)
			printf("*");
		printf("\n");
	}
}