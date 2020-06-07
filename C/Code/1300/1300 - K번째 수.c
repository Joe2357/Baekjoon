#include <stdio.h>
#define min(a, b) (((a) > (b)) ? (b) : (a))

long long n, k;

int main() {
	// input
	scanf("%lld %lld", &n, &k);

	// binary search
	long long start = 1, end = n * n;
	while (start < end) {
		long long temp = 0, mid = (start + end) / 2;

		// numbering smaller than mid
		for (long long i = 1; i <= n && i <= mid; i++)
			temp += min(n, mid / i);

		// lower-bound search	
		if (temp < k)
			start = mid + 1;
		else
			end = mid;
	}
	printf("%lld", start);
	return 0;
}