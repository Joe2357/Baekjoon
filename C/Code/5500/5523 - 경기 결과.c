#include <stdio.h>

int main() {
	int a = 0, b = 0, t;
	for (scanf("%d", &t); t; t--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		a += (t1 > t2), b += (t1 < t2);
	}
	printf("%d %d", a, b);
	return 0;
}