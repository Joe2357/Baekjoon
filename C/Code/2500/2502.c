#include <stdio.h>

int main() {
	int arr[31] = {0, 1}, a, b;
	for (int i = 2; i < 31; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	scanf("%d %d", &a, &b);
	for (int i = 1; i <= b; i++) {
		for (int j = 1; j <= b; j++) {
			int temp = arr[a - 2] * i + arr[a - 1] * j;
			if (temp == b) {
				printf("%d\n%d", i, j);
				return 0;
			} else if (temp > b)
				break;
		}
	}
	return 0;
}