#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {		// look like n * n square
		for (int j = 0; j < n; j++)
			if (j < n - i - 1)
				printf(" ");
			else
				printf("*");
		printf("\n");
	}
	return 0;
}