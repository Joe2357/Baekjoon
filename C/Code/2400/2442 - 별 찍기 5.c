#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {			// row
		for (int j = 0; j < n - i - 1; j++)	// column
			printf(" ");
		for (int j = 0; j < 2 * i + 1; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}