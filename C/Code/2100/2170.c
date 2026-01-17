#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int x, y;
} ND;

#define MAX_IDX 1000000
ND arr[MAX_IDX];
int n;

int start_point_asc(const void* p, const void* q) {
	ND* a = (ND*)p;
	ND* b = (ND*)q;

	if (a->x < b->x) {
		return -1;
	} else if (a->x > b->x) {
		return 1;
	} else {
		return end_point_asc(p, q);
	}
}

int end_point_asc(const void* p, const void* q) {
	ND* a = (ND*)p;
	ND* b = (ND*)q;

	if (a->y < b->y) {
		return -1;
	} else if (a->y > b->y) {
		return 1;
	} else {
		return 0;
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

	qsort(arr, n, sizeof(ND), start_point_asc);

	ND cur = arr[0];
	int retval = 0;
	for (int i = 1; i < n; ++i) {
		if (cur.y >= arr[i].x) {
			cur.y = max(cur.y, arr[i].y);
		} else {
			retval += (cur.y - cur.x);
			cur = arr[i];
		}
	}

	retval += (cur.y - cur.x);
	printf("%d", retval);
	return 0;
}