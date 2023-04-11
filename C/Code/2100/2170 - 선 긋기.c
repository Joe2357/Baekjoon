#include <stdio.h>

typedef struct Node {
	int a, b;
} ND;

#define MAX_IDX 1000000
ND arr[MAX_IDX];
int n;

int cmp(ND* x, ND* y) {
	if (x->a == y->a) {
		return x->b > y->b;
	} else {
		return x->a > y->a;
	}
}

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[i] = (ND){a, b};
	}

	qsort(arr, n, sizeof(ND), cmp);

	ND cur = arr[0];
	int retval = 0;
	for (int i = 1; i < n; ++i) {
		if (cur.b >= arr[i].a) {
			cur.b = max(cur.b, arr[i].b);
		} else {
			retval += (cur.b - cur.a);
			cur = arr[i];
		}
	}

	retval += (cur.b - cur.a);
	printf("%d", retval);
	return 0;
}