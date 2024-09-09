#include <stdio.h>

#define MAX_IDX 1000

int weight[MAX_IDX];
int n;

int cmp(int* a, int* b) { return *a > *b; }

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", weight + i);
	}

	qsort(weight, n, sizeof(int), cmp);

	int ret;
	if (weight[0] != 1) {
		ret = 1;
	} else {
		int sum = 1;
		for (int i = 1; i < n; ++i) {
			if (weight[i] > sum + 1) {
				ret = sum + 1;
				break;
			}
			sum += weight[i];
			ret = sum + 1;
		}
	}

	printf("%d", ret);
	return 0;
}