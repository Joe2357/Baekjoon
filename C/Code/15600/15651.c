#include <stdio.h>

void dfs(int* arr, int n, int kmax, int a) {
	if (a == kmax) {
		for (int i = 0; i < a; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[a] = i;
		dfs(arr, n, kmax, a + 1);
	}
	return;
}

int main(n, k) {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int arr[8] = {i};
		dfs(arr, n, k, 1);
	}
	return 0;
}