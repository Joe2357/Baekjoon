#include <stdio.h>

int main() {
	int arr[50], n, left = 0, right = 0, max = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);						// get all trophy's tall
		if (arr[i] > max)							// finding tallest trophy
			left++, max = arr[i];					// add 1 to left variable ( can see ar left side )
	}
	max = 0;
	for (; n; n--)
		if (arr[n - 1] > max)						// finding tallest trophy
			right++, max = arr[n - 1];				// add 1 to right varialbe ( can see ar right side )
	printf("%d\n%d", left, right);
	return 0;
}