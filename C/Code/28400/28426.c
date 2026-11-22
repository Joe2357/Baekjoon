#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 2; i < n; i += 2) {
		printf("%d %d ", i * 6 - 4, i * 6 - 2);
	}
	printf("%s", (n % 2 == 1) ? "3" : "3 6");
	return 0;
}