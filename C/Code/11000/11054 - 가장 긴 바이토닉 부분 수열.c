#include <stdio.h>
#define max(a, b) (a < b) ? b : a

int main(n) {
	int arr[1000], LIS[2][1000] = { 0 }, result = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	for (int i = 0; i < n; i++) { // toward right LIS
		if (!LIS[0][i])
			LIS[0][i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j] && LIS[0][i] < LIS[0][j] + 1)
				LIS[0][i] = LIS[0][j] + 1;
	}
	for (int i = n - 1; i >= 0; i--) { // toward left LIS
		if (!LIS[1][i])
			LIS[1][i] = 1;
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j] && LIS[1][i] < LIS[1][j] + 1)
				LIS[1][i] = LIS[1][j] + 1;
	}
	for (int i = 0; i < n; i++) // bitonic = left + right - 1
		result = max(result, LIS[0][i] + LIS[1][i] - 1);
	printf("%d", result);
	return 0;
}