#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {					// row
		for (int j = 0; j < i; j++)
			printf(" ");
		for (int j = 0; j < 2 * n - 2 * i - 1; j++)	// column
			printf("*");
		printf("\n");
	}
	return 0;
}