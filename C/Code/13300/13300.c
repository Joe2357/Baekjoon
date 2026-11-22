#include <stdio.h>

#define MAX_IDX 1000

int student[2][7];

int n, k;

int main(void) {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int s, y;
		scanf("%d %d", &s, &y);
		student[s][y] += 1;
	}

	int ret = 0;
	for (int s = 0; s < 2; ++s) {
		for (int y = 1; y <= 6; ++y) {
			ret += (student[s][y] / k);
			ret += ((student[s][y] % k) > 0);
		}
	}
	printf("%d", ret);
	return 0;
}
