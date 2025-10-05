#include <stdio.h>

const int DIGIT = 10;

#define max(a, b) (((a) > (b)) ? (a) : (b))

int reverse(int x) {
	int ret = 0;
	while (x > 0) {
		ret *= DIGIT;
		ret += (x % DIGIT);
		x /= DIGIT;
	}
	return ret;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", max(reverse(a), reverse(b)));
	return 0;
}