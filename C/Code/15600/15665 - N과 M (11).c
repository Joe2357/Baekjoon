#include <stdio.h>

void back(int *arr, int *result, int m, int a) {
	if (m == a) {
		for (int i = 0; i < a; i++)
			printf("%d ", result[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= 10000; i++) {
		if (arr[i]) {
			result[a] = i;
			back(arr, result, m, a + 1);
		}
	}
	return;
}

int main(m, n) {
	int arr[10001] = { 0 }, result[8] = { 0 };
	for (scanf("%d %d", &n, &m); n; n--) {
		int temp;
		scanf("%d", &temp);
		arr[temp]++;
	}
	back(arr, result, m, 0);
	return 0;
}