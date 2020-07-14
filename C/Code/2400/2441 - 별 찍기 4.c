#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	for (int i = n; i > 0; i--) {		// row
		for (int j = 0; j < n; j++)		// column
			if (j <= n - i - 1)
				printf(" ");
			else
				printf("*");
		printf("\n");
	}
	return 0;
}