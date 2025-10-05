#include <stdio.h>

const int MAX_IDX = 7;
const int INF = 987654321;

#define min(a, b) (((a) > (b)) ? (b) : (a))

int main() {
	int odd_sum = 0;
	int odd_min = INF;

	for (int i = 0; i < MAX_IDX; ++i) {
		int a;
		scanf("%d", &a);
		if (a % 2 > 0) {
			odd_sum += a;

			if (a < odd_min) {
				odd_min = a;
			}
		}
	}

	if (odd_sum == 0) {
		printf("-1");
	} else {
		printf("%d\n%d", odd_sum, odd_min);
	}
	return 0;
}