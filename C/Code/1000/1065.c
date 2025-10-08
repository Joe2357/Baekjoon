#include <stdio.h>

typedef char bool;
const bool true = 1;
const bool false = 0;

bool is_hansu(int n) {
	if (n < 100) {
		return true;
	} else {
		int hundreds = n / 100;
		int tens = (n / 10) % 10;
		int units = n % 10;
		return (hundreds - tens) == (tens - units);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int count = 0;
	for (int i = 1; i <= n; ++i) {
		count += is_hansu(i);
	}
	printf("%d", count);
	return 0;
}