#include <stdio.h>
#define MAX_INDEX 1000

int lis[MAX_INDEX], length;

int lowerBound(int value) {
	// init
	int start = 0, end = length;

	// find correct position
	while (start < end) {
		// set mid pos
		int mid = (start + end) / 2;

		// move forward
		if (lis[mid] < value)
			start = mid + 1;
		else
			end = mid;
	}
	return end;
}

int main() {
	// init
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { // get 1 integer, push to LIS ( O(nlogn) )
		int temp;
		scanf("%d", &temp);

		// find position using Lower Bound binary-search
		int pos = lowerBound(temp);
		lis[pos] = temp;
		length += (pos == length);
	}

	// print result
	printf("%d", length);
	return 0;
}