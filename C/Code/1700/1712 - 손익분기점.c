#include <stdio.h>

int main(a, b, c) {
	scanf("%d %d %d", &a, &b, &c);
	int temp = c - b;
	if (temp <= 0) {				// loss >= gain, so we can never get income
		printf("-1");
		return 0;
	}
	int temp1 = a / temp;			// money / (income - outcome ) = day
	printf("%d", temp1 + 1);		// next day we can get income
	return 0;
}