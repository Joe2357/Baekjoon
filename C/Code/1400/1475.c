#include <stdio.h>

#define DIGIT 10

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
	int number[DIGIT] = {0};
	int n;
	for (scanf("%d", &n); n > 0; n /= DIGIT) {
		switch (n % DIGIT) {
			case 6:
			case 9: {
				number[6] += 1;
				break;
			}
			default: {
				number[n % DIGIT] += 1;
				break;
			}
		}
	}

	number[6] = (number[6] + 1) / 2;
	int ret = 0;
	for (int i = 0; i < DIGIT; ++i) {
		ret = max(ret, number[i]);
	}
	printf("%d", ret);
	return 0;
}