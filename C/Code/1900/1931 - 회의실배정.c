#include <stdio.h>

typedef struct Conference {	// start time, end time
	int start, end;
} CF;

CF arr[100000];
int end, result;		// current end time, result

int cmp(CF* a, CF* b) {		// qsort compare function
	return a->end - b->end + (a->start - b->start) * (a->end == b->end); // ascending end. if same, ascending start
}

void check(int target) {				// greedy pick
	if (arr[target].start < end)	// if can't pick
		return;
	end = arr[target].end;			// end = time spent
	result++;
	return;
}

int main(n) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)						// arr input
		scanf("%d %d", &arr[i].start, &arr[i].end);
	qsort(arr, n, sizeof(CF), cmp);					// sort
	for (int i = 0; i < n; i++)						// greedy pick
		check(i);
	printf("%d", result);
	return 0;
}