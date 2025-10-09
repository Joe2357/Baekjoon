#include <stdio.h>
#include <stdlib.h>

typedef struct Conference {
	int start;
	int end;
} Conference;

#define MAX_IDX (int)(1e5)

Conference conferences[MAX_IDX];
int n;

int start_asc(const void* a, const void* b) {
	Conference* c1 = (Conference*)a;
	Conference* c2 = (Conference*)b;
	if (c1->start > c2->start) {
		return 1;
	} else if (c1->start < c2->start) {
		return -1;
	} else {
		return 0;
	}
}
int end_asc(const void* a, const void* b) {
	Conference* c1 = (Conference*)a;
	Conference* c2 = (Conference*)b;
	if (c1->end > c2->end) {
		return 1;
	} else if (c1->end < c2->end) {
		return -1;
	} else {
		return start_asc(a, b);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &conferences[i].start, &conferences[i].end);
	}
	qsort(conferences, n, sizeof(Conference), end_asc);

	int reserved = 0;
	int last_end_time = 0;
	for (int i = 0; i < n; ++i) {
		if (conferences[i].start >= last_end_time) {
			reserved += 1;
			last_end_time = conferences[i].end;
		}
	}
	printf("%d", reserved);
	return 0;
}