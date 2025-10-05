#include <stdio.h>

const int DIGIT = 10;

int min_v = 0, max_v = 0;

void preprocess(int x) {
	for (int digit = 1; x > 0; digit *= DIGIT) {
		int d = x % DIGIT;

		switch (d) {
			case 5:
			case 6: {
				min_v += (5 * digit);
				max_v += (6 * digit);
				break;
			}
			default: {
				min_v += (d * digit);
				max_v += (d * digit);
				break;
			}
		}

		x /= DIGIT;
	}
	return;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	preprocess(a), preprocess(b);
	printf("%d %d", min_v, max_v);
	return 0;
}