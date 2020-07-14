#include <stdio.h>
#define max(a, b) (a < b) ? b : a

typedef struct Line {
	int start, end;
} LN;

int compare(LN* a, LN* b) {			// start ascending sort
	return a->start - b->start;
}

int main(n) {
	scanf("%d", &n);
	LN arr[100];
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].start, &arr[i].end);
	qsort(arr, n, sizeof(LN), compare);								// sort
	int LIS[100] = { 0 }, result = -1;
	for (int i = 0; i < n; i++) {									// Longest Increase Sequence Algorithm
		if (!LIS[i])
			LIS[i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[i].end > arr[j].end && LIS[i] < LIS[j] + 1)
				LIS[i] = LIS[j] + 1, result = max(result, LIS[i]);	// result = LIS of Line
	}
	printf("%d", n - result);										// all of line - LIS line = remove target line
	return 0;
}