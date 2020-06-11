#include <stdio.h>

int main() {
	int arr[10] = { 0 }, n;
	scanf("%d", &n);
	do {
		arr[n % 10]++;				// how many times did digit appear?
		n /= 10;
	} while (n);
	arr[6] += arr[9];				// 6 and 9 are same
	arr[6] += (arr[6] % 2);			// add 1 if count(6) is odd
	arr[6] /= 2;					// we can use 9 to create 6
	int max = arr[0];
	for (int i = 0; i < 9; i++)		// max value search
		if (arr[i] > max)
			max = arr[i];
	printf("%d", max);
	return 0;
}