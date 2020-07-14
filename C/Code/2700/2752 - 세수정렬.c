#include <stdio.h>

int main(t) {
	int arr[3];
	for (int i = 0; i < 3; i++)
		scanf("%d", arr + i);
	for (int i = 0; i < 2; i++)             // bubble sort
		for (int j = 0; j < 3 - i - 1; j++)
			if (arr[j] > arr[j + 1])
				t = arr[j + 1],
				arr[j + 1] = arr[j],
				arr[j] = t;
	for (int i = 0; i < 3; i++)
		printf("%d ", arr[i]);
	return 0;
}