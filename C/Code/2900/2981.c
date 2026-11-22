#include <stdio.h>
#define min(a, b) (a > b) ? b : a

int cmp(int* a, int* b) {
	return *a - *b;
}

int GCD(int a, int b) {
	if (!b)
		return a;
	return GCD(b, a % b);
}

int main(n) {
	int arr[100], tarr[10000], a = 0, temp = 1000000001;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	qsort(arr, n, sizeof(int), cmp);
	for (int i = 0; i < n - 1; i++)
		temp = min(temp, arr[i + 1] - arr[i]);
	temp = GCD(arr[n - 1] - arr[0], temp);
	for (int i = 2; i * i <= temp; i++) {
		if (!(temp % i)) {
			tarr[a++] = i;
			if (i * i != temp)
				tarr[a++] = temp / i;
		}
	}
	tarr[a++] = temp;
	qsort(tarr, a, sizeof(int), cmp);
	for (int i = 0; i < a; i++)
		printf("%d ", tarr[i]);
	return 0;
}