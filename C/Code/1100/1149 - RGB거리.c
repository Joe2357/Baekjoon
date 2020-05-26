#include <stdio.h>

int main() {
	int arr[3][1000] = { 0 }, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &arr[0][i], &arr[1][i], &arr[2][i]);
		if (i) {																			// Dynamic Programming
			arr[0][i] += (arr[1][i - 1] > arr[2][i - 1]) ? arr[2][i - 1] : arr[1][i - 1];
			arr[1][i] += (arr[0][i - 1] > arr[2][i - 1]) ? arr[2][i - 1] : arr[0][i - 1];
			arr[2][i] += (arr[0][i - 1] > arr[1][i - 1]) ? arr[1][i - 1] : arr[0][i - 1];
		}
	}
	int min = (arr[0][n - 1] > arr[1][n - 1]) ? arr[1][n - 1] : arr[0][n - 1];				// finding minimum
	min = (min > arr[2][n - 1]) ? arr[2][n - 1] : min;
	printf("%d", min);
	return 0;
}