#include <stdio.h>

int main(n) {
	scanf("%d", &n);
	int arr[1001] = {0, 1, 3};
	for (int i = 3; i <= n; i++)
		arr[i] = (arr[i - 1] + arr[i - 2] * 2) % 10007;
	printf("%d", arr[n]);
	return 0;
}