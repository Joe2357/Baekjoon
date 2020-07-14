#include <stdio.h>

int main() {
	long long n;
	scanf("%lld", &n);
	n %= 1500000;               // Pisano Period
	int arr[3] = { 0, 1, 1 };     // only using 3 space
	for (int t = 2; t <= n; t++)    // arr[i] = sum of other 2 values
		arr[t % 3] = (arr[(t - 1) % 3] + arr[(t - 2) % 3]) % 1000000;
	printf("%d", arr[n % 3]);
	return 0;
}