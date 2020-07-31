#include <stdio.h>
#include <math.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	long long result = pow(a, 2) - pow(b, 2);
	printf("%lld", result);
	return 0;
}