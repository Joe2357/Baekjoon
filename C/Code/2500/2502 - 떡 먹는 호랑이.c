#include <stdio.h>

int main() {
	int arr[31] = { 0,1 }, a, b;
	for (int i = 2; i < 31; i++)							// fibbo
		arr[i] = arr[i - 1] + arr[i - 2];
	scanf("%d %d", &a, &b);
	for (int i = 1; i <= b; i++) {							// brute force
		for (int j = 1; j <= b; j++) {
			int temp = arr[a - 2] * i + arr[a - 1] * j;		// calc
			if (temp == b) {								// if correct value
				printf("%d\n%d", i, j);						// print result
				return 0;
			}
			else if (temp > b)								// if unlikely value
				break;
		}
	}
	return 0;
}