#include <stdio.h>

int main() {
	int arr[100001] = { 0, 3, 7 }, n;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++)
		arr[i] = arr[i - 2] + arr[i - 1] * 2, arr[i] %= 9901;
	printf("%d", arr[n]);
	return 0;
}