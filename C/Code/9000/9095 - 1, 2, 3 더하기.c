#include <stdio.h>

int main(t, n) {
	int arr[12] = { 1, 1, 2 }; // dynamic programming
	for (t = 3; t < 12; t++)
		arr[t] = arr[t - 1] + arr[t - 2] + arr[t - 3];
	// t = (t - 1) + 1, (t - 2) + 2, (t - 3) + 3
	for (scanf("%d", &t); t; t--) {
		scanf("%d", &n);
		printf("%d\n", arr[n]); // print result
	}
	return 0;
}