#include <stdio.h>

const int NONE = -1;

int main() {
	int m, n;
	scanf("%d %d", &m, &n);

	int sum_square = 0, min_square = NONE;
	for (int i = 1; i * i <= n; ++i) {
		if (m <= i * i) {
			sum_square += (i * i);
			if (min_square == NONE) {
				min_square = (i * i);
			}
		}
	}

	if (sum_square == 0)
		printf("-1");
	else
		printf("%d\n%d", sum_square, min_square);
	return 0;
}