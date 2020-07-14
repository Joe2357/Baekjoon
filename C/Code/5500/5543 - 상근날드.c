#include <stdio.h>

int main(a, b, t, i) {
	b = 3, i = 2;
	// the cheapest hamburger
	for (a = 9999; b; b--) {
		scanf("%d", &t);
		a = (t < a) ? t : a;
	}
	// the cheapest drink
	for (b = 9999; i; i--) {
		scanf("%d", &t);
		b = (t < b) ? t : b;
	}
	// set = a + b - 50
	printf("%d", a + b - 50);
	return 0;
}