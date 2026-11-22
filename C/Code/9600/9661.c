#include <stdio.h>

int main() {
	long long n;
	scanf("%lld", &n);
	if (!( n % 5 ) || ( n % 5 == 2 ))
		printf("CY");
	else
		printf("SK");
	return 0;
}