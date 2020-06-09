#include <stdio.h>

int main() {
	int arr[1000001] = { 0 }, n;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {										// reverse search
		int temp = arr[i - 1] + 1;										// +1
		if (!(i % 2))													// x2
			temp = (temp >= (arr[i / 2] + 1)) ? arr[i / 2] + 1 : temp;
		if (!(i % 3))													// x3
			temp = (temp >= (arr[i / 3] + 1)) ? arr[i / 3] + 1 : temp;
		arr[i] = temp;													// smallest value
	}
	printf("%d", arr[n]);
	return 0;
}