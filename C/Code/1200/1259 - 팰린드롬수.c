#include <stdio.h>

int main(n) {
	for (scanf("%d", &n); n; scanf("%d", &n)) { // while input is not 0
		int i = 10000, boolean = 1;
		while (!(n / i)) // strip()
			i /= 10;
		while (n >= 10) { // while not a digit
			if (n / i != n % 10) { // not a Palindrom
				boolean = 0;
				break;
			}
			n %= i, n /= 10, i /= 100;
		}
		(boolean) ? printf("yes\n") : printf("no\n");
	}
	return 0;
}