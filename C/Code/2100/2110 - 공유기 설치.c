#include <stdio.h>
#define MAX_INDEX 200000

int arr[MAX_INDEX], n, c;

int cmp(int *a, int *b) {
	return *a - *b;
}

int getTemp(int dist) {
	// first set device to the first place
	int setDevice = 1,
		currentDistance = arr[0];
	
	// check whether we can place device in that place
	for (int i = 1; i < n; i++)
		if (arr[i] - currentDistance >= dist)
			setDevice++, currentDistance = arr[i];
	
	// how many devices were placed?
	return (setDevice >= c);
}

int main() {
	// input
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	
	// position sort ascending order
	qsort(arr, n, sizeof(int), cmp);
	
	// binary search
	int start = 0, end = arr[n - 1];
	while (start + 1 < end) {
		int mid = (start + end) / 2,
			tempR = getTemp(mid);
		if (tempR)
			start = mid;
		else
			end = mid - 1;
	}
	// check error case
	end -= !(getTemp(end));
	printf("%d", end);
	return 0;
}