#include <stdio.h>

int ret[5];
const int Q1 = 0;
const int Q2 = 1;
const int Q3 = 2;
const int Q4 = 3;
const int AXIS = 4;

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int x, y;
		scanf("%d %d", &x, &y);

		ret[Q1] += (x > 0 && y > 0);
		ret[Q2] += (x < 0 && y > 0);
		ret[Q3] += (x < 0 && y < 0);
		ret[Q4] += (x > 0 && y < 0);
		ret[AXIS] += (x == 0 || y == 0);
	}

	printf("Q1: %d\n", ret[Q1]);
	printf("Q2: %d\n", ret[Q2]);
	printf("Q3: %d\n", ret[Q3]);
	printf("Q4: %d\n", ret[Q4]);
	printf("AXIS: %d\n", ret[AXIS]);
	return 0;
}