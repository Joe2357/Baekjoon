#include <stdio.h>
#define max(a, b) (a > b) ? a : b

int main(n) {
	int arr[2][301] = { 0 };				// dynamic programming
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		if (i == 1)							// start point
			arr[0][i] = temp;
		else
			arr[0][i] = temp + max(arr[0][i - 2], arr[1][i - 2]);	// not Continuous
		arr[1][i] = arr[0][i - 1] + temp;							// Continuous
	}
	printf("%d", max(arr[0][n], arr[1][n]));
	return 0;
}