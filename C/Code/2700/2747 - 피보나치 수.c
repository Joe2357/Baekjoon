#include <stdio.h>

int main(n) {
	int arr[46] = { 0, 1 };					// arr[0] = 0, arr[1] = 1
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)			// fib(a) = fib(a - 1) + fib(a - 2)
		arr[i] = arr[i - 1] + arr[i - 2];
	printf("%d", arr[n]);
	return 0;
}