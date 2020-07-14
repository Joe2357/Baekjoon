#include <stdio.h>

int arr[5][5], result[5][5], n;
long long p;

void mul(int arr1[5][5], int arr2[5][5]) { // matrix multiple function
	int res[5][5];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			long long temp = 0;
			for (int a = 0; a < n; a++)
				temp += arr1[i][a] * arr2[a][j] % 1000;
			res[i][j] = temp % 1000;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr1[i][j] = res[i][j];
	return;
}

void power() { // power function O(nlogn)
	while (p) {
		if (p % 2)
			mul(result, arr);
		mul(arr, arr);
		p /= 2;
	}
	return;
}

int main() {
	scanf("%d %lld", &n, &p);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			result[i][j] = arr[i][j];
		}
	power(--p); // a^p = a * a^p-1
	for (int i = 0; i < n; i++) { // print result
		for (int j = 0; j < n; j++)
			printf("%d ", result[i][j] % 1000);
		printf("\n");
	}
}