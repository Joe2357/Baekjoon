#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	for (int a = 0; a < 2 * n; a++) {
		for (int b = 0; b < n; b++)
			if ((a + b) % 2)
				printf(" ");
			else
				printf("*");
		printf("\n");
	}
	return 0;
}