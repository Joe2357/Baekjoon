#include <stdio.h>

void back(int *arr, int n, int kmax, int a) {
	if (a == kmax) { // search finish
		for (int i = 0; i < a; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) { // need more search
		int boolean = 1;
		for (int j = 0; j < a; j++) {
			if (arr[j] == i) { // overlapped
				boolean = 0;
				break;
			}
		}
		if (boolean) { // add number
			arr[a] = i;
			back(arr, n, kmax, a + 1);
		}
	}
	return;
}

int main(n, k) {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int arr[8] = { i };
		back(arr, n, k, 1);
	}
	return 0;
}