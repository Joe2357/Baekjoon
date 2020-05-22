#include <stdio.h>

/*
	A : 1230
	B : 8719
	Then, last digit ( 0 ~ 9 ) appears (871 - 123 + 1) times
*/

int result[10], n, exp = 1, start = 0;

void calc(int a) { // calculate digit
	while (a)
		result[a % 10] += exp, a /= 10;
	return;
}

int main() {
	scanf("%d", &n);
	while (start != n) // while condition
	{
		if (start % 10 || !start) // start : end with 0, end = end with 9
			calc(start++);
		else if (n % 10 != 9)
			calc(n--);
		else { // calculating result
			int temp = (n / 10 - start / 10 + 1);
			for (int i = 0; i < 10; i++)
				result[i] += temp * exp;
			start /= 10, n /= 10, exp *= 10;
		}
	}
	calc(start);
	for (int i = 0; i < 10; i++) // print result
		printf("%d ", result[i]);
	return 0;
}