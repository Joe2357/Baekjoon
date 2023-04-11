#include <stdio.h>

typedef struct Node {
	int x, y;
} ND;

#define MAX_IDX 100
const int DEFAULT = 1;

ND arr[MAX_IDX];
int n;
int LIS[MAX_IDX];

int cmp(ND* a, ND* b) { return a->x > b->x; }

#define max(a, b) (((a) > (b)) ? (a) : (b))
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[i] = (ND){a, b};
	}

	qsort(arr, n, sizeof(ND), cmp);

	int retval = 0;
	for (int i = 0; i < n; ++i) {
		LIS[i] = DEFAULT;
		for (int j = 0; j < i; ++j) {
			if (arr[j].y < arr[i].y) {
				LIS[i] = max(LIS[j] + 1, LIS[i]);
			}
		}
		retval = max(retval, LIS[i]);
	}

	printf("%d", n - retval);
	return 0;
}