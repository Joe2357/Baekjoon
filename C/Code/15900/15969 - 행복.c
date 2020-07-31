#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int arr[1000];
	int max = -1, min = 2000;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	printf("%d", max - min);
	return 0;
}