#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
	int l, a, b, c, d;
	scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);

	int day1 = (a + (c - 1)) / c;
	int day2 = (b + (d - 1)) / d;
	printf("%d", l - max(day1, day2));
	return 0;
}