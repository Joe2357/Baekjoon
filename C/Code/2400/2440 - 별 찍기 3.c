#include <stdio.h>

int main(n) {
	for (scanf("%d", &n); n; n--) {	// row
		for (int j = 0; j < n; j++)	// column
			printf("*");
		printf("\n");
	}
	return 0;
}