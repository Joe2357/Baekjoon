#include <stdio.h>

int main(t, n) {
	for (scanf("%d", &t); t; t--) {
		scanf("%d", &n);
		int arr[41] = { 0 };													// arr[n] = how many times we have to operate
		arr[n] = 1;																// first, we have to operate fibonacci(n) once
		while (n > 1)
			arr[n - 1] += arr[n], arr[n - 2] += arr[n], n--;					// fibonacci(n) = fibonacci(n - 1) + fibonacci(n - 2)
		printf("%d %d\n", arr[0], arr[1]);
	}
	return 0;
}