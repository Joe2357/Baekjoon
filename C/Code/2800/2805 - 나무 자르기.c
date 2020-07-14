#include <stdio.h>

int main() {
	long long n, m;
	scanf("%lld %lld", &n, &m);
	int arr[1000000];
	long long sum = 0, start = 0, end;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		sum += arr[i];
	}
	for (end = sum; start < end;) { // upper bound binary search
		long long temp = 0, mid = (start + end) / 2;
		for (int i = 0; i < n; i++)
			temp += (arr[i] - mid) * (arr[i] >= mid); // meters that was cut
		if (temp >= m)
			start = mid + 1;
		else
			end = mid;
	}
	printf("%lld", end - 1);
	return 0;
}