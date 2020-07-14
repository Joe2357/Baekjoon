#include <stdio.h>

int cmp(int *a, int *b) {
	return *a - *b;
}

int main() {
	int arr[5], avg = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", arr + i);
		avg += arr[i];                  // average sum
	}
	qsort(arr, 5, sizeof(int), cmp);    // sort ascending
	printf("%d\n%d", avg / 5, arr[2]);  // average, middle value print
	return 0;
}