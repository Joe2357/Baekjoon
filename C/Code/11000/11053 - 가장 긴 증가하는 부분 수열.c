#include <stdio.h>

int main() {
	int arr[1000], n, LIS[1000] = { 0 }, max = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	for (int i = 0; i < n; i++) { // O(N^2) LIS
		if (!LIS[i])
			LIS[i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j])
				if (LIS[i] < LIS[j] + 1)
					LIS[i] = LIS[j] + 1;
		if (LIS[i] > max)
			max = LIS[i];
	}
	printf("%d", max);
	return 0;
}