#include <stdio.h>

int main(n, k) {
	int arr[10000], a = 0, b = 0, result = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	int sum = arr[0];
	while (n - b) {
		if (k == sum)
			result++, sum += arr[++b] - arr[a++];
		else if (k > sum)
			sum += arr[++b];
		else
			sum -= arr[a++];
	}
	printf("%d", result);
	return 0;
}