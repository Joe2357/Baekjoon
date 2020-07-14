#include <stdio.h>
#define max(a, b) (a > b) ? a : b

/*
	arr[0] -> pre X, cur X
	arr[1] -> pre X, cur O
	arr[2] -> pre O, cur X
	arr[3] -> pre O, cur O
*/

int arr[4][10001];

int main(n) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		int pre = max(arr[1][i - 1], arr[3][i - 1]);		// drank previous
		arr[2][i] = pre, arr[3][i] = arr[1][i - 1] + temp;
		pre = max(arr[0][i - 1], arr[2][i - 1]);			// didn't drink previous
		arr[0][i] = pre, arr[1][i] = pre + temp;
	}
	int result = max(arr[0][n], arr[1][n]);					// search biggest value
	result = max(arr[2][n], result);
	result = max(arr[3][n], result);
	printf("%d", result);
	return 0;
}