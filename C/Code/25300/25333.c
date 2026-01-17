#include <stdio.h>

int gcd(int a, int b) {
	while (b > 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b, x;
		scanf("%d %d %d", &a, &b, &x);
		printf("%d\n", x / gcd(a, b));
	}
	return 0;
}