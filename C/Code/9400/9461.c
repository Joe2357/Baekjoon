#include <stdio.h>

int main() {
	long long arr[101] = {1, 1, 1, 2, 2};
	for (int i = 5; i <= 100; i++)
		arr[i] = arr[i - 1] + arr[i - 5];
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", arr[n - 1]);
	}
	return 0;
}