#include <stdio.h>

int main() {
	long long a, b, c;
	scanf("%lld %lld", &a, &b);
	scanf("%lld", &c);
	if (a + b >= 2 * c)
		printf("%lld", a + b - 2 * c);
	else
		printf("%lld", a + b);
	return 0;
}