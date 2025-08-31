#include <stdio.h>

int get_gcd(int a, int b) {
	return (b > 0) ? get_gcd(b, a % b) : a;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	int gcd = get_gcd(a, b);
	int lcm = a * b / gcd;

	printf("%d\n%d", gcd, lcm);
	return 0;
}