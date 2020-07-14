#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {		// print square
		for (int j = 0; j < n; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}