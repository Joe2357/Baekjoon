#include <stdio.h>

int main(n) {
	// init
	scanf("%d", &n);
	int target = 2;

	// while number is not 1
	while (n != 1)
		if (!(n % target)) {							// if target is a divisor of n
			n /= target;			// divide
			printf("%d\n", target); // print ( the smallest divisor )
		}
		else
			target++;
	return 0;
}