#include <stdio.h>

long long fibo(int a) {
	if (a < 2)
		return a;
	return fibo(a - 1) + fibo(a - 2);
}

int recursive() {
	int n;
	scanf("%d", &n);
	printf("%lld", fibo(n));
	return 0;
}

int dp() {
	long long arr[21] = { 0, 1 };
	for (int i = 2; i < 21; i++) // dynamic programming
		arr[i] = arr[i - 1] + arr[i - 2];
	int n;
	scanf("%d", &n);
	printf("%lld", arr[n]);
	return;
}

int main() {
	// recursive();
	dp();
	return 0;
}