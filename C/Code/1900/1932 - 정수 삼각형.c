#include <stdio.h>
#define max(a, b) ((a > b) ? a : b)

int main(n, temp) {
	int arr[500][500];
	scanf("%d %d", &n, &arr[0][0]);
	for (int i = 1; i < n; i++) {
		scanf("%d", &temp);						// arr[x][0] = arr[x - 1][0] + temp
		arr[i][0] = arr[i - 1][0] + temp;
		for (int j = 1; j < i; j++) {			// arr[x][y] = temp + (bigger? arr[x - 1][y - 1], arr[x - 1][y])
			scanf("%d", &temp);
			arr[i][j] = max(arr[i - 1][j - 1], arr[i - 1][j]) + temp;
		}
		scanf("%d", &temp);						// arr[x][n] = arr[x - 1][n - 1] + temp
		arr[i][i] = arr[i - 1][i - 1] + temp;
	}
	int maxValue = -1;
	for (int i = 0; i < n; i++)					// finding max value
		maxValue = max(maxValue, arr[n - 1][i]);
	printf("%d", maxValue);
	return 0;
}