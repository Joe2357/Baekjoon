#include <stdio.h>

int main() {
	int n, x;
	scanf("%d %d", &n, &x);
	while (n--) {
		int a;
		scanf("%d", &a);
		if (a < x) {
			printf("%d ", a);
		}
	}
	return 0;
}