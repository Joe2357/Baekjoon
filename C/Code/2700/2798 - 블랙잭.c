#include <stdio.h>

int main(n, m) {
	scanf("%d %d", &n, &m);
	int arr[100];
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	for (int i = 0; i < n - 1; i++)			// bubble sort
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
	int result = 0;
	for (int i = 0; i < n - 2; i++)			// brute force
		for (int j = i + 1; j < n - 1; j++)
			for (int k = j + 1; k < n; k++) {
				int temp = arr[i] + arr[j] + arr[k];	// sum of 3 cards
				if ((temp <= m) && (temp > result))		// condition
					result = temp;
			}
	printf("%d", result);
	return 0;
}