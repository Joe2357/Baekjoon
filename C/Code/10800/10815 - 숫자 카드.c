#include <stdio.h>
#define MAX_INDEX 500000
#define True 1
#define False 0

typedef char boolean;

int arr[MAX_INDEX], n;

// quickSort compare function
int cmp(int *a, int *b) {
	return *a - *b;
}

// binary search function
boolean isInArray(int target) {
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == target)
			return True;
		else if (arr[mid] > target)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return False;
}

int main() {
	// init
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	
	// sort array before perform binary search
	qsort(arr, n, sizeof(int), cmp);
	
	// call binary search function
	int m;
	for (scanf("%d", &m); m; m--) {
		int temp;
		scanf("%d", &temp);
		printf("%d ", isInArray(temp));
	}
	
	return 0;
}