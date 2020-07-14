#include <stdio.h>

int getGCD(int a, int b) {          // recursive function
	if (!b)
		return a;                   // greatest common divisor
	return getGCD(b, a % b);
}

int main(a, b) {
	scanf("%d %d", &a, &b);
	int gcd = getGCD(a, b);         // greatest common divisor
	printf("%d\n%d", gcd, a * b / gcd);   // lcm * gcd = a * b
	return 0;
}