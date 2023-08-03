#include <stdio.h>

#define MAX_IDX (int)(3e5)
int arr[MAX_IDX];
int n;

int cmp(int* a, int* b) { return *a > *b; }

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}
	if (n == 0) {
		printf("0");
		return 0;
	}

	qsort(arr, n, sizeof(int), cmp);

	double temp = (double)(n)*3 / 20;
	int deletedMember = temp;
	if (temp - deletedMember >= 0.50000) {
		++deletedMember;
	}

	int sum = 0;
	for (int i = deletedMember; i < n - deletedMember; ++i) {
		sum += arr[i];
	}
	temp = (double)(sum) / (n - 2 * deletedMember);
	int retval = temp;
	if (temp - retval >= 0.50000) {
		++retval;
	}

	printf("%d", retval);
	return 0;
}