#include <stdio.h>
#define max(a, b) (a > b) ? a : b

int cmp(int* a, int* b) {
	return *a - *b;
}

int main(n) {
	double sum = 0;
	int arr[500000], count[8001] = { 0 }, maxCount = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		sum += arr[i];
		count[arr[i] + 4000]++;							// count how many times numbers input?
		maxCount = max(maxCount, count[arr[i] + 4000]);	// renew max count of number
	}
	qsort(arr, n, sizeof(int), cmp);
	printf("%.0lf\n", sum / n);				// 1st average
	printf("%d\n", arr[n / 2]);				// 2nd average
	int temp = -1;
	for (int i = 0; i < 8001; i++)
		if (count[i] == maxCount)			// if that is mode ( max count of number )
			if (temp != -1) {				// that's second mode
				temp = i;
				break;
			}
			else							// first mode
				temp = i;
	printf("%d\n", temp - 4000);			// 3rd average
	printf("%d\n", arr[n - 1] - arr[0]);	// 4th average
	return 0;
}