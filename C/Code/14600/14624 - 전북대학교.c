#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	if (!(n % 2)) { // even number
		printf("I LOVE CBNU");
		return 0;
	}

	// case of odd number
	for (int i = 0; i < n; i++)
		printf("*");
	printf("\n");
	n = n / 2 + 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++)
			printf(" ");
		printf("*");
		if (i) {
			for (int j = 0; j < 2 * i - 1; j++)
				printf(" ");
			printf("*");
		}
		printf("\n");
	}
	return 0;
}