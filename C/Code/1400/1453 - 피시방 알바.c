#include <stdio.h>

int main() {
	int arr[100] = { 0 }, n, result = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if (!arr[temp - 1])				// no one is in target seat
			arr[temp - 1] = 1;			// now someone is in target seat
		else
			result++;					// denied person counting
	}
	printf("%d", result);
	return 0;
}