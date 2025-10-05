#include <stdio.h>

const int DIGIT = 10;

int rev(int x) {
	int ret = 0;
	while (x > 0) {
		ret = ret * DIGIT + (x % DIGIT);
		x /= DIGIT;
	}
	return ret;
}

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d", rev(rev(x) + rev(y)));
	return 0;
}