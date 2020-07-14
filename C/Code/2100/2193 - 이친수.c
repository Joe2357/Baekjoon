#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	long arr[91] = { 0,1,1 };				// 1 : "1", 2 : "00"
	for (int i = 2; i <= n; i++)
		arr[i] = arr[i - 1] + arr[i - 2];	// i : "1" + (i - 1), "10" + (i - 2)
	printf("%ld", arr[n]);
	return 0;
}