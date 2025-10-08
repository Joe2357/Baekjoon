#include <stdio.h>

int gcd(int a, int b) {
	while (b > 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	int n, m;
	scanf("%d:%d", &n, &m);
	int g = gcd(n, m);
	printf("%d:%d\n", n / g, m / g);
	return 0;
}