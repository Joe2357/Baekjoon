#include <stdio.h>

int main() {
	long long n;
	scanf("%lld", &n);
	if (n % 2)
		printf("SK");
	else
		printf("CY");
	return 0;
}