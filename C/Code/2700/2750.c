#include <stdio.h>

#define MAX_IDX 1000

int arr[MAX_IDX];

// 퀵소트 구현
void plainQuickSort(int left, int right) {
	int less[MAX_IDX], lessLength = 0;
	int same[MAX_IDX], sameLength = 0;
	int more[MAX_IDX], moreLength = 0;
	int pivot = arr[left];

	for (int a = left + 1; a <= right; a++) {
		if (arr[a] < pivot) {
			less[lessLength++] = arr[a];
		} else if (arr[a] == pivot) {
			same[sameLength++] = arr[a];
		} else {
			more[moreLength++] = arr[a];
		}
	}

	int i = left;

	for (int a = 0; a < lessLength; a++, i++) {
		arr[i] = less[a];
	}

	arr[i++] = pivot;

	for (int a = 0; a < sameLength; a++, i++) {
		arr[i] = same[a];
	}
	for (int a = 0; a < moreLength; a++, i++) {
		arr[i] = more[a];
	}
	if (lessLength > 1) {
		plainQuickSort(left, left + lessLength - 1);
	}
	if (moreLength > 1) {
		plainQuickSort(right - moreLength + 1, right);
	}
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	plainQuickSort(0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}