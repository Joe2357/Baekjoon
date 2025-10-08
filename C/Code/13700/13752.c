#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int k;
		scanf("%d", &k);
		while (k--) {
			printf("=");
		}
		printf("\n");
	}
	return 0;
}