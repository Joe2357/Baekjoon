#include <stdio.h>

const int MAX_LENGTH = 64;

int main() {
	int x;
	scanf("%d", &x);

	int result = 0;
	for (int i = MAX_LENGTH; x > 0; i >>= 1) {
		if (x >= i) {
			x -= i;
			result += 1;
		}
	}
	printf("%d", result);
	return 0;
}