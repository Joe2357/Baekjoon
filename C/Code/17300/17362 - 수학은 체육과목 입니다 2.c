#include <stdio.h>

int main(n) {
	int arr[8] = { 1, 2, 3, 4, 5, 4, 3, 2 };
	scanf("%d", &n);
	printf("%d\n", arr[(n - 1) % 8]);
	return 0;
}