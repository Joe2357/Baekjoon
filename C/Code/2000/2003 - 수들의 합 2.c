#include <stdio.h>

int main(n, k) {
	int arr[10000], a = 0, b = 0, result = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)						// input grid
		scanf("%d", arr + i);
	int sum = arr[0];								// sum = sum of arr[a] ~ arr[b]
	while (n != b)
		if (k == sum)								// if target
			result++, sum += arr[++b] - arr[a++];	// move all pointer
		else if (k > sum)							// sum < target
			sum += arr[++b];						// move right pointer
		else										// sum > target
			sum -= arr[a++];						// move left pointer
	printf("%d", result);
	return 0;
}