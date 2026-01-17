#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

const int MIN_VALUE = 1;
const int MAX_VALUE = 10000;

int main() {
	srand((unsigned int)time(NULL));

	int a, b;
	int exclude_1 = (rand() % MAX_VALUE + MIN_VALUE), exclude_2 = (rand() % MAX_VALUE + MIN_VALUE);

	for (int i = MIN_VALUE; i <= MAX_VALUE; ++i) {
		if (i == exclude_1 || i == exclude_2) {
			continue;
		}

		printf("? A %d\n", i);
		fflush(stdout);

		scanf("%d", &a);
		if (a == true) {
			a = i;
			break;
		}
	}

	for (int i = MIN_VALUE; i <= MAX_VALUE; ++i) {
		if (i == exclude_1 || i == exclude_2) {
			continue;
		}

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