#include <stdio.h>

int cmp(int* a, int* b) {
	return *a - *b;
}

int main() {
	int n, a[50], b[50], temp[101] = { 0 }, result = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)					// array 1
		scanf("%d", a + i);
	for (int i = 0; i < n; i++) {
		scanf("%d", b + i);
		temp[b[i]]++;							// temp = how many times did index appear?
	}
	qsort(a, n, sizeof(int), cmp);				// ascending sort
	for (int temp2 = 0; n; n--) {
		while (!temp[temp2])					// finding smallest value
			temp2++;
		temp[temp2]--;
		result += a[n - 1] * temp2;				// eval value
	}
	printf("%d", result);
	return 0;
}