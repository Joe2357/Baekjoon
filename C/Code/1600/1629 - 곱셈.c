#include <stdio.h>

unsigned long long getPow(int a, int b, int c) {								// recursive function
	if (!b)																		// a^0 = 1
		return 1;
	unsigned long long result = getPow(a, b / 2, c) * getPow(a, b / 2, c) % c;	// a^b = ( a^2 ) ^ ( b/2 )
	if (b % 2)																	// {* a ( if b%2 == 1 )} 
		result = result * a % c;
	return result;
}

int main(a, b, c) {
	scanf("%d %d %d", &a, &b, &c);
	printf("%llu", getPow(a, b, c) % c); 	// unsigned long long ( number max range out of long long )
	return 0;
}