#include <stdio.h>
#define MAX_INDEX 100

int GCD(int a, int b) {
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}

int main() {

	// loop testcase
	int t;
	for (scanf("%d", &t); t; t--) {
		// init
		int n;
		scanf("%d", &n);
		int arr[MAX_INDEX];
		long long sum = 0;

		// input
		for (int i = 0; i < n; i++)
			scanf("%d", arr + i);

		// brute force
		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)
				sum += GCD(arr[i], arr[j]);

		// print result
		printf("%lld\n", sum);
	}
	return 0;
}