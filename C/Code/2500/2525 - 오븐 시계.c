#include <stdio.h>

int main(a, b, c) {
	scanf("%d %d %d", &a, &b, &c);
	b += c, a += b / 60;				// calc
	printf("%d %d", a % 24, b % 60);	// 24 hour 60 min
	return 0;
}