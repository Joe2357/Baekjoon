#include <stdio.h>

int main(n) {
	int arr[1000001] = { 1,1 };						// arr[0] = X, arr[1] = "1"
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;	// arr[n] = arr[n - 2] + "00" + arr[n - 1] + "1"
	printf("%d", arr[n]);							// print result
	return 0;
}