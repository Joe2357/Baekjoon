#include <stdio.h>

int main(a, b, t1, t2) {
	scanf("%d %d %d", &t1, &t2, &a);
	a += t1 * 3 + t2 * 2;
	scanf("%d %d %d", &t1, &t2, &b);
	b += t1 * 3 + t2 * 2;
	if (a > b)
		printf("A");
	else if (a < b)
		printf("B");
	else
		printf("T");
	return 0;
}