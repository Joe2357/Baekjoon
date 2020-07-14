#include <stdio.h>
#define max(a, b) (a > b) ? a : b

int main(a, b) {
	scanf("%d %d", &a, &b);
	a = a % 10 * 100 + a / 10 % 10 * 10 + a / 100,  // change a
		b = b % 10 * 100 + b / 10 % 10 * 10 + b / 100;  // change b
	printf("%d", max(a, b));    // print max value
	return 0;
}