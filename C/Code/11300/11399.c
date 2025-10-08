#include <stdio.h>
#include <stdlib.h>

int compare(const void*, const void*);

int main() {
	int arr[1001] = {0}, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		arr[i] = temp;
	}
	qsort(arr, n, sizeof(arr[0]), compare);
	int result = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			result += arr[j];
	printf("%d", result);
	return 0;
}

int compare(const void* a, const void* b) {
	int num1 = *(int*)a, num2 = *(int*)b;
	return num1 - num2;
}