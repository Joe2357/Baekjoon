#include <stdio.h>

int main(t) {
	long long arr[101] = { 1,1,1,2,2 };
	for (int i = 5; i <= 100; i++) // dynamic programming
		arr[i] = arr[i - 1] + arr[i - 5];
	for (scanf("%d,&t")t; t; t--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", arr[n - 1]); // print result
	}
	return 0;
}