#include <stdio.h>

int main() {
	long long n, t = 2;
	scanf("%lld", &n);
	n %= 1500000;
	int arr[3];
	arr[0] = 0, arr[1] = 1;
	while (t <= n) {
		arr[t % 3] = ( arr[( t - 1 ) % 3] + arr[( t - 2 ) % 3] ) % 1000000;
		t++;
	}
	printf("%d", arr[n % 3]);
	return 0;
}