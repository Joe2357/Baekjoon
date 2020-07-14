#include <stdio.h>

int cmp(int* a, int* b) {
	return *a - *b;
}

int main() {
	int arr[9], sum = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", arr + i);
		sum += arr[i];
	}
	for (int i = 0; i < 8; i++)						// brute force
		for (int j = i + 1; j < 9; j++)
			if (arr[i] + arr[j] == sum - 100) {
				arr[i] = -1, arr[j] = -1;			// erase value
				qsort(arr, 9, sizeof(int), cmp);	// ascending sort
				for (int a = 2; a < 9; a++)			// never print -1
					printf("%d\n", arr[a]);
				return 0;
			}
}