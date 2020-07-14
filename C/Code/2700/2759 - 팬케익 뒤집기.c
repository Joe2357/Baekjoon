#include <stdio.h>

int flip(int *arr, int *result, int target, int rear) {
	if (target == 1)
		return 0; // false
	else {
		result[rear] = target; // flip count
		int progress = 0, temp;
		while (progress < target - progress - 1) // while area all flipping
			temp = arr[progress],
			arr[progress] = arr[target - progress - 1],
			arr[target - progress - 1] = temp,
			progress++;
		return 1; // true
	}
}

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int n, arr[30], result[60], rear = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", arr + i);
		for (; n > 1; n--)                  // while not sorted
			for (int j = 0; j < n - 1; j++) // find target point
				if (arr[j] == n)            // if target point ( the biggest value that not sorted )
				{
					rear += flip(arr, result, j + 1, rear); // flip n to top
					rear += flip(arr, result, n, rear);     // flip all ( totally all fancake is sorted )
					break;
				}
		printf("%d ", rear);
		for (int i = 0; i < rear; i++)
			printf("%d ", result[i]);
		printf("\n");
	}
	return 0;
}