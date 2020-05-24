#include <stdio.h>

int main(n, a, b, count) {
	scanf("%d %d %d", &n, &a, &b);
    for (count = 0; a != b;)							// a, b get new number
        count++, a = a / 2 + a % 2, b = b / 2 + b % 2;	// count the match
	printf("%d", count);
	return 0;
}