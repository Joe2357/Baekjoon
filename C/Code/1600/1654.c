#include <stdio.h>

int main(k, n) {
	int arr[10000];
	scanf("%d %d", &k, &n);
	long long start = 1, end, sum = 0;
	for (int i = 0; i < k; i++) {
		scanf("%d", arr + i);
		sum += arr[i];
	}
	if (n == 1 && k == 1) {
		printf("%d", arr[0]);
		return 0;
	}
	for (end = sum; start < end;) {
		long long mid = (start + end) / 2;
		int count = 0;
		for (int i = 0; i < k; i++)
			count += (arr[i] / mid);
		if (count >= n)
			start = mid + 1;
		else
			end = mid;
	}
	printf("%lld", end - 1);
	return 0;
}