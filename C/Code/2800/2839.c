#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	for (int a = n / 5; a >= 0; a--) {
		int b = (n - a * 5);
		if (!(b % 3)) {
			printf("%d", a + b / 3);
			return 0;
		}
	}
	printf("-1");
	return 0;
}