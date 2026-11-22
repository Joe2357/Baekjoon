#include <stdio.h>
#define min(a, b) (((a) > (b)) ? (b) : (a))

long long n, k;

int main() {
	scanf("%lld %lld", &n, &k);
	long long start = 1, end = n * n;
	while (start < end) {
		long long temp = 0, mid = (start + end) / 2;
		for (long long i = 1; i <= n && i <= mid; i++)
			temp += min(n, mid / i);
		if (temp < k)
			start = mid + 1;
		else
			end = mid;
	}
	printf("%lld", start);
	return 0;
}