#include <stdio.h>
#include <stdlib.h>

struct Cood {
	int x, y;
};
typedef struct Cood CD;

int compare(CD *a, CD *b) {
	if (a->x == b->x)
		return a->y - b->y;
	else
		return a->x - b->x;
}

int main() {
	// init
	CD arr[100000];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].x, &arr[i].y);

	// ascending order sort ( x -> y )
	qsort(arr, n, sizeof(arr[0]), compare);

	// print result
	for (int i = 0; i < n; i++)
		printf("%d %d\n", arr[i].x, arr[i].y);
	return 0;
}