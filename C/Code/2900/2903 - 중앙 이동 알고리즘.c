#include <stdio.h>
#include <math.h>

/*
	iter 0 = 4 ( 2 * 2 )
	iter 1 = 9 ( 3 * 3 )
	iter 2 = 25 ( 5 * 5 )
	iter 3 = 81 ( 9 * 9 )
*/

int main(n) {
	scanf("%d", &n);
	printf("%.0lf", pow(pow(2, n) + 1, 2)); // calc
	return 0;
}