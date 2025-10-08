#include <stdio.h>
#include <stdlib.h>

typedef struct Position {
	int x, y;
} Position;

#define MAX_IDX 100000

Position arr[MAX_IDX];
int n;

int position_asc(const void* a, const void* b) {
	Position pa = *(Position*)a;
	Position pb = *(Position*)b;

	if (pa.y != pb.y) {
		return pa.y - pb.y;
	} else {
		return pa.x - pb.x;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}
	qsort(arr, n, sizeof(Position), position_asc);
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
	return 0;
}