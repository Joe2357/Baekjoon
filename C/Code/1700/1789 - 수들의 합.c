#include <stdio.h>
#include <math.h>

int main() {
	unsigned int s, i;				// value condition : 1 ~ 4294967295 ( max of unsigned int ) 
	scanf("%u", &s);
	i = sqrt((double)s * 2);		// estimated value
	while (i * (i + 1) > s * 2)		// a * ( a + 1 ) / 2 = sum of 1 ~ a
		i--;						// finding result value
	printf("%u", i);
	return 0;
}