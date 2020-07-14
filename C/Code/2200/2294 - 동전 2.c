#include <stdio.h>
#define min(a, b) (a > b) ? b : a
#define MAX 999999

int main(n, k) {
	int arr[10001] = { 0 };
	for (int i = 1; i < 10001; i++)
		arr[i] = MAX;
	for (scanf("%d %d", &n, &k); n; n--) {				// coin count
		int temp;										// coin value
		scanf("%d", &temp);
		for (int j = temp; j <= k; j++)					// dynamic programming
			arr[j] = min(arr[j - temp] + 1, arr[j]);
	}
	printf("%d", (arr[k] != MAX) ? arr[k] : -1);
	return 0;
}