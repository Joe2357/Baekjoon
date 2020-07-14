#include <stdio.h>

int main(n) {
	long long arr[100] = { 0, 1 };			// fib(90) is not in range of int, but range in long long
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)			// same as Problem 2747
		arr[i] = arr[i - 1] + arr[i - 2];
	printf("%lld", arr[n]);
	return 0;
}