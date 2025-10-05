#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	b += c;
	while (b >= 60) {
		a += 1;
		b -= 60;
	}
	printf("%d %d", a % 24, b);
	return 0;
}