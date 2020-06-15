#include <stdio.h>

int main(k, n) {
	int arr[10000];
	scanf("%d %d", &k, &n);
	long long start = 1, end, sum = 0;
	for (int i = 0; i < k; i++) {
		scanf("%d", arr + i);
		sum += arr[i];
	}
	if (n == 1 && k == 1)               // exception case
		printf("%d", arr[0]);
	else
		for (end = sum; start < end;)   // upper bound binary search
		{
			long long mid = (start + end) / 2, count = 0;
			for (int i = 0; i < k; i++)
				count += (arr[i] / mid);	// number that we can get 'count' lines its length is 'mid' 
			if (count >= n)
				start = mid + 1;
			else
				end = mid;
		}
	printf("%lld", end - 1);            // end = the first point its value is bigger than n
	return 0;
}