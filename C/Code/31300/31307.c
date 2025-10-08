#include <stdio.h>

#define MAX_IDX 50
const int HOUR = 5;

int loc[MAX_IDX];

int cmp(int* a, int* b) {
	return *a > *b;
}

int main() {
	int n, lph;
	scanf("%d %d", &n, &lph);
	for (int i = 0; i < n; ++i) {
		scanf("%d", loc + i);
	}
	qsort(loc, n, sizeof(int), cmp);

	int res = 0;
	int sum = 0;
	int thr = HOUR * lph;
	for (int i = 0; i < n; ++i) {
		if (sum + loc[i] <= thr) {
			sum += loc[i];
			++res;
		} else {
			break;
		}
	}
	printf("%d", res);
	return 0;
}