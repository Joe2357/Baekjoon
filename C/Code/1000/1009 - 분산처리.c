#include <stdio.h>
#include <math.h>															// using pow function ( a ^ b )

int main(t) {
	for (scanf("%d", &t); t; t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		a %= 10, b = (!(b % 4)) ? 4 : b % 4;								// we only need to power 'a' max 4 times
		int result = (!(int)pow(a, b) % 10) ? 10 : (int)pow(a, b) % 10;		// if result is 0, Computer No.10 will treat this data
		printf("%d\n", result);
	}
	return 0;
}