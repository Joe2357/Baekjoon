#include <stdio.h>

void back(int* arr, int* target, int n, int kmax, int a) {
	if (a == kmax) {
		for (int i = 0; i < a; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		int boolean = 1;
		for (int j = 0; j < a; j++) {
			if (arr[j] > target[i]) {
				boolean = 0;
				break;
			}
		}
		if (boolean) {
			arr[a] = target[i];
			back(arr, target, n, kmax, a + 1);
		}
	}
	return;
}

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main(n, k) {
	scanf("%d %d", &n, &k);
	int target[8], arr[8];
	for (int i = 0; i < n; i++)
		scanf("%d", target + i);
	qsort(target, n, sizeof(int), compare);
	back(arr, target, n, k, 0);
	return 0;
}