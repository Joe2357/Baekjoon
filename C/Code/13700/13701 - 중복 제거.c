#include <stdio.h>

int main() {
	// bitwise memorization
	int arr[(1 << 25) / 32] = { 0 }, num;
	while (~scanf("%d", &num)) { // while EOF
		// search profit position
		int quotient = num / 32, remainder = 1 << (num % 32);

		if (!(arr[quotient] & remainder)) {								// if not stored yet
			arr[quotient] += remainder; // store value
			printf("%d ", num);			// print number
		}
	}
	return 0;
}