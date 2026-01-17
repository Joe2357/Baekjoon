#include <stdio.h>

typedef int bool;
const bool true = 1;
const bool false = 0;

const int MIN_VALUE = 1;
const int MAX_VALUE = 9;

int main() {
	int a, b;

	for (int i = MIN_VALUE; i <= MAX_VALUE; ++i) {
		printf("? A %d\n", i);
		fflush(stdout);

		scanf("%d", &a);
		if (a == true) {
			a = i;
			break;
		}
	}

	for (int i = MIN_VALUE; i <= MAX_VALUE; ++i) {
		printf("? B %d\n", i);
		fflush(stdout);

		scanf("%d", &b);
		if (b == true) {
			b = i;
			break;
		}
	}

	printf("! %d", a + b);
	fflush(stdout);
	return 0;
}