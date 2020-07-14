#include <stdio.h>

int main(t, a, b) {
	int arr[5] = { 0 };
	for (scanf("%d", &t); t; t--) {
		scanf("%d %d", &a, &b);
		if (!a || !b) // Axis
			arr[0]++;
		else // get grid
			arr[2 * (b < 0) + (a * b < 0) + 1]++;
	}
	// print result
	for (t = 1; t < 5; t++)
		printf("Q%d: %d\n", t, arr[t]);
	printf("AXIS: %d", arr[0]);
	return 0;
}