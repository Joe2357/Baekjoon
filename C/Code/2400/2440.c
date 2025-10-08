#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		for (int j = 0; j < n; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}