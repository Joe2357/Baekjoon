#include <stdio.h>

#define MAX_IDX_PER_STEP 8

int arr[MAX_IDX_PER_STEP] = {1, 2, 3, 4, 5, 4, 3, 2};

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", arr[(n - 1) % MAX_IDX_PER_STEP]);
	return 0;
}