#include <stdio.h>

int main() {
	int n, x, t;
	scanf("%d %d %d", &n, &x, &t);
	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == x) {
			x = b;
		}
		else if (b == x) {
			x = a;
		}
	}
	printf("%d", x);
	return 0;
}