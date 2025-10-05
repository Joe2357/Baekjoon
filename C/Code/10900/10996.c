#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%c", ((i + j) % 2 > 0) ? ' ' : '*');
		}
		printf("\n");
	}
	return 0;
}