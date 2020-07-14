#include <stdio.h>

int main(n) {
	int arr[1000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)                 // input
		scanf("%d", arr + i);
	for (int i = 0; i < n - 1; i++)             // bubble sort
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1],
					arr[j + 1] = temp;
			}
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	return 0;
}