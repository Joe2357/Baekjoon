#include <stdio.h>

int main(a, b) {
	int digit = 100000, boolean = 0;
	for (scanf("%d %d", &a, &b); digit; digit /= 10) {
		int temp = a / digit + b / digit;
		a %= digit, b %= digit;
		if (temp || boolean) {
			boolean = 1; // check the number is not 0
			printf("%d", temp);
		}
	}
	return 0;
}