#include <stdio.h>

#define DIGIT 10

int main() {
	int number[DIGIT] = {0}, n;
	for (scanf("%d", &n); n > 0; n /= DIGIT) {
		number[n % DIGIT] += 1;
	}

	for (int i = DIGIT - 1; i >= 0; --i) {
		while (number[i]--) {
			printf("%d", i);
		}
	}
	return 0;
}