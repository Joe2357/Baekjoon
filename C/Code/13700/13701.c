#include <stdio.h>

int main() {
	int arr[(1 << 25) / 32] = { 0 }, num;
	while (~scanf("%d", &num)) {
		int quotient = num / 32, remainder = 1 << (num % 32);
		if (!(arr[quotient] & remainder)) {
			arr[quotient] += remainder;
			printf("%d ", num);
		}
	}
	return 0;
}