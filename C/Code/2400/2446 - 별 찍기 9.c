#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {					// reverse pyramid
		for (int j = 0; j < i; j++)
			printf(" ");
		for (int j = 0; j < 2 * n - 2 * i - 1; j++)
			printf("*");
		printf("\n");
	}
	for (int i = 0; i < n - 1; i++)
		printf(" ");
	printf("*\n");
	for (int i = 0; i < n - 1; i++)	{					// pyramid
		for (int j = 0; j < n - i - 2; j++)
			printf(" ");
		for (int j = 0; j < 2 * i + 3; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}