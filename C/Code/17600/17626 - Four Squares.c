#include <stdio.h>
#define min(a, b) (a > b) ? b : a

int main(n) {
	// init
	int arr[50001] = { 0 };
	for (int i = 1; i <= 50000; i++)
		arr[i] = 9;

	// dp
	for (int i = 1; i * i <= 50000; i++) {
		arr[i * i] = 1;
		for (int t = i * i + 1; t <= 50000; t++)
			arr[t] = min(arr[t], arr[t - i * i] + 1);
	}

	// print result
	scanf("%d", &n);
	printf("%d", arr[n]);
	return 0;
}