#include <stdio.h>

int main(t, n) {
	int arr[11] = {1, 1, 2};
	for (t = 3; t < 11; t++)
		arr[t] = arr[t - 1] + arr[t - 2] + arr[t - 3];
	for (scanf("%d", &t); t; t--) {
		scanf("%d", &n);
		printf("%d\n", arr[n]);
	}
	return 0;
}