#include <stdio.h>

int main(n, t) {
	int arr[20000001] = {0};
	for (scanf("%d", &n); n; n--) {
		int temp;
		scanf("%d", &temp);
		arr[temp + 10000000]++;
	}
	for (scanf("%d", &t); t; t--) {
		int temp;
		scanf("%d", &temp);
		printf("%d ", arr[temp + 10000000]);
	}
	return 0;
}