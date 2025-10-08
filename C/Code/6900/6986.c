#include <stdio.h>
#include <stdlib.h>
#define ERROR_NUM 0.00000001

int compare(double* a, double* b) {
	return (*a > *b);
}

int main(n, k) {
	scanf("%d %d", &n, &k);

	double arr[100000], trim = 0, bojung = 0;
	for (int i = 0; i < n; i++)
		scanf("%lf", arr + i);

	// double ascending order
	qsort(arr, n, sizeof(double), compare);

	// calc all sum of array
	for (int i = 0; i < k; i++)
		bojung += arr[k];
	for (int i = k; i < n - k; i++)
		trim += arr[i], bojung += arr[i];
	for (int i = n - k; i < n; i++)
		bojung += arr[n - k - 1];

	// average
	bojung /= n, trim /= (n - 2 * k);

	// floating point error
	printf("%.2lf\n%.2lf", trim + ERROR_NUM, bojung + ERROR_NUM);
	return 0;
}