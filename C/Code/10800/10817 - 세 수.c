#include <stdio.h>

int main(a, b, c) {
	scanf("%d %d %d", &a, &b, &c);
	int temp;
	if (a < b) {
		temp = a;
		a = b;
		b = temp;
	}
	if (c > a)
		printf("%d", a);
	else if (c > b)
		printf("%d", c);
	else
		printf("%d", b);
	return 0;
}