#include <stdio.h>

int main(n) {
	int result = 0, temp = 100000000, a = 9;	// a = digit of temp
	for (scanf("%d", &n); n; n--) {				// n ~ 1
		while (n < temp)						// how many digits n has?
			temp /= 10, a--;					// a is current number of digit
		result += a;
	}
	printf("%d", result);						// print result
	return 0;
}