#include <stdio.h>

int main() {
	int a1, a0;
	int c;
	int n0;
	scanf("%d %d %d %d", &a1, &a0, &c, &n0);

	if (c < a1) {
		printf("0");
	} else {
		printf("%d", (a1 * n0 + a0 <= c * n0));
	}
	return 0;
}