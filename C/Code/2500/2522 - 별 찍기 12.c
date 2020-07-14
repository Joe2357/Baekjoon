#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {			// upstairs
		for (int j = 0; j < n - i - 1; j++)
			printf(" ");
		for (int j = 0; j < i + 1; j++)
			printf("*");
		printf("\n");
	}
	for (int i = 0; i < n; i++)					// middle
		printf("*");
	printf("\n");
	for (int i = 0; i < n - 1; i++) {			// downstairs
		for (int j = 0; j < i + 1; j++)
			printf(" ");
		for (int j = 0; j < n - i - 1; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}