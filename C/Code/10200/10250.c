#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int h, w, n;
		scanf("%d %d %d", &h, &w, &n);
		printf("%d%02d\n", (n - 1) % h + 1, (n - 1) / h + 1);
	}
	return 0;
}