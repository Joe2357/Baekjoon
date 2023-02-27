#include <stdio.h>

#define DECIMAL 10
int result[DECIMAL];
int n;
int d = 1;	// number of digit
int s = 0;	// start

void calc(int x) {
	while (x > 0) {
		result[x % 10] += d;
		x /= 10;
	}
	return;
}

int main() {
	scanf("%d", &n);

	// make subproblem
	while (s < n) {
		if (s == 0 || s % 10 > 0) {	 // make start point's end digit to 0, but not 0
			calc(s);
			++s;
		} else if (n % 10 != 9) {  // make end point's end digit to 9
			calc(n);
			--n;
		} else {  // solve subproblem
			int repeatTime = (n / 10 - s / 10 + 1);
			for (int i = 0; i < DECIMAL; ++i) {
				result[i] += repeatTime * d;
			}

			s /= 10, n /= 10, d *= 10;	// discard the end digit
		}
	}
	calc(n);  // last number

	for (int i = 0; i < DECIMAL; ++i) {
		printf("%d ", result[i]);
	}
	return 0;
}